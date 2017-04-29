#include "server.h"

#define NUM_RESPONSES 10

typedef enum 
{
    // error strings
    ERROR=0,
    CLIENT_ERROR,
    SERVER_ERROR,
    // storage command responses 
    STORED,
    EXISTS,
    NOT_FOUND,
    // retrieval command responses
    END,
    // deletion 
    // incr/decr
    DELETED,
    // touch
    TOUCHED

} RESPONSE;

struct RESPONSE_STRING_MAP
{
    RESPONSE rsp;
    char* res_str;
};

RESPONSE_STRING_MAP RESPONSE_MAP[NUM_RESPONSES]
{
    // error strings
    {ERROR,(char*)"error"},
    {CLIENT_ERROR,(char*)"client_error"},
    {SERVER_ERROR,(char*)"server_error"},
    // storage command responses 
    {STORED,(char*)"stored"},
    {EXISTS,(char*)"exists"},
    {NOT_FOUND,(char*)"not_found"},
    // retrieval command responses
    {END,(char*)"end"},
    // deletion 
    // incr/decr
    {DELETED,(char*)"deleted"},
    {NOT_FOUND,(char*)"not_found"},
    // touch
    {TOUCHED,(char*)"touched"}
};

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
    if(bind(server_socket, (struct sockaddr*) 
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

    long client_socket = (long)args;
    char  buffer[buf_size] = {0};
    int bytesReceived = 0;
    printf(" On thread : %ld \n", client_socket);
    while(true)
    {
        //read from socket
        
        recv(client_socket, buffer, buf_size, 0);

        printf("Message from Client %ld is : %s",client_socket, buffer);

        // parse command
        parse_command(buffer,buf_size);
        
        send(client_socket, "END", sizeof("END"), 0);

        //action on command
    }	
}
