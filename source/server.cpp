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
    pthread_exit(NULL);
    return 0;

}

void *beginConnect(void *args){

#define buf_size 256

    Stats::Instance().curr_connections++;

    long client_socket = (long)args;
    char  buffer[buf_size] = {0};
    
    size_t response_length;

    printf(" On thread : %ld \n", client_socket);
    while(true)
    {
        //read from socket
        buffer[buf_size] = {0};
        char* response_str=nullptr;


        memset(buffer, 0, sizeof(buffer));
        printf("*********%s",buffer);

        recv(client_socket, buffer, buf_size, 0);

        printf("Message from Client %ld is : %s\n",client_socket, buffer);

        // parse command
        parse_command(buffer,buf_size, response_str, &response_length);

        printf("got response %s, length=%d\n",response_str,response_length);

        if(response_str!=nullptr) {
            if (std::strcmp(response_str, "QUIT\r\n") == 0) {
                free(response_str);
                close(client_socket);
                break;
            }
        }
        send(client_socket, response_str, response_length, 0);

        if(response_str!=nullptr)
        {
            free(response_str);
        }
        //action on command
    }	
}
