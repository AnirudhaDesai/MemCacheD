#include "server.h"
#include "stats.h"

int initializeServer(){
    long  server_socket, client_socket;
    int Error, opt=0;

    pthread_t threadID;

    if((server_socket = socket(AF_INET, SOCK_STREAM, 0))==0)
    {
        perror("Server Socket Creation Failed \n");
        exit(EXIT_FAILURE);
    }

    if( setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, 
          sizeof(opt)) < 0 )  
    {  
        perror("setsockopt");  
        exit(EXIT_FAILURE);  
    }

    //define the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9005);
    server_address.sin_addr.s_addr = INADDR_ANY;

    //bind the socket to our specified IP and port
    if(::bind(server_socket, (struct sockaddr*)
        &server_address, sizeof(server_address))<0)
    {
        perror("Bind Failed\n");
        exit (EXIT_FAILURE);
    }

    printf("Waiting for Connections.. \n");

    listen(server_socket, 5);

    while(true){
        client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1){
            return 1;
        }

        printf("Client Connected: %ld\n", client_socket);
        // run pthread on client_socket

        Error = pthread_create(&threadID, NULL, &beginConnect, (void *)client_socket );
        if (Error != 0)
            printf("Error creating thread\n");
    }
   // pthread_exit(NULL);
    return 0;

}

void *beginConnect(void *args){

#define buf_size 255

    Stats::Instance().curr_connections++;
    Stats::Instance().total_connections++;
    Stats::Instance().connection_structures++;

    long client_socket = (long)args;
    char  buffer[buf_size] = {0};
    bool need_more_data = false;
    
    char* response_str=nullptr;
    size_t response_length;
    ssize_t received_size = 0;
    PARSE_ERROR parse_error;
    std::string command;

    printf(" On thread : %ld \n", client_socket);
    while(true)
    {
        response_str = nullptr;

        //read from socket
        if(!need_more_data)
        {
            command = "";
        }

        do
        {
            buffer[buf_size] = {0};
            memset(buffer, 0, buf_size);
            received_size = recv(client_socket, buffer, buf_size, 0);
            printf("received %u\n bytes",received_size);
            command += std::string(buffer);
        }
        while(received_size == buf_size);

        if(received_size <= 0)
        {
            close(client_socket);
            return nullptr;
        }

        if(command.length() <= 1024*1024)
        {

            printf("Command from Client %ld of size %u is : \n",client_socket,command.size(), command.c_str());
            // parse command
            parse_error = parse_command(command, response_str, &response_length);
        }
        else
        {
            printf("Command from Client %ld of size %u is too long",client_socket,command.size());
            parse_error = PARSE_ERROR::INVALID_COMMAND;
            response_str = (char*)malloc(strlen("ERROR\r\n")+1);
            strcpy(response_str,"ERROR\r\n");
            response_length = strlen(response_str);
        }


        printf("got response %s, length=%d\n",response_str,response_length);
        printf("parse_error%d\n", parse_error);

        switch(parse_error)
        {
            case PARSE_ERROR::NONE:
            case PARSE_ERROR::INVALID_COMMAND:
                printf("sending response %s, length=%d\n",response_str,response_length);
                send(client_socket, response_str, response_length, 0);
                break;
            case PARSE_ERROR::QUIT: 
                if(response_str!=nullptr)
                    free(response_str);
                Stats::Instance().curr_connections--;
                close(client_socket);
                return nullptr;
                break;
            case PARSE_ERROR::NEED_MORE_DATA:
                break;
        }
            
        if(response_str!=nullptr)
        {
            free(response_str);
        }
        
    }
    //End of this connection with client. Update Stats
    printf("\nEnd of thread\n");
    Stats::Instance().curr_connections--;	
}
