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
    NOT_FOUND,
    // touch
    TOUCHED

} RESPONSE;

struct RESPONSE_STRING_MAP
{
    RESPONSE rsp;
    char* res_str;
};

RESPONSE CMD_MAP[NUM_RESPONSES]
{
    // error strings
    {ERROR,"error"},
    {CLIENT_ERROR,"client_error"},
    {SERVER_ERROR,"server_error"},
    // storage command responses 
    {STORED,"stored"},
    {EXISTS,"exists"},
    {NOT_FOUND,"not_found"},
    // retrieval command responses
    {END,"end"},
    // deletion 
    // incr/decr
    {DELETED,"deleted"},
    {NOT_FOUND,"not_found"},
    // touch
    {TOUCHED,"touched"}
};

int initializeServer(){
    int  server_socket, client_socket;
    int Error;
    pthread_t threadID;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket == -1){
        return 1;
    }

    //define the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    //bind the socket to our specified IP and port
    bind(server_socket, (struct sockaddr*) 
            &server_address, sizeof(server_address));

    printf("Starting Listen..\n");

    listen(server_socket, 5);

    while(true){
        client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1){
            return 1;
        }

        printf("Accepted From Client: %d\n", client_socket);
        // run pthread on client_socket

        error = pthread_create(&threadID, NULL, &eventAction, (void *)client_socket );
        if (error != 0)
            printf("Error creating thread\n");
    }
    pthread_exit(NULL);
    return 0;

}

void *eventAction(void *args){


    long client_socket = (long)args;
    char  buffer[256] = {0};
    int bytesReceived = 0;
    printf(" On thread : %l \n", client_socket);
    while(true)
    {
        //read from socket
        //printf("Entered eventAction : \n");

        recv(client_socket, buffer, sizeof(buffer), 0);

        printf("%s",buffer);

        //parse command
        //action on command
    }	
}
