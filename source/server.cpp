#include "server.h"

int initializeServer(){
	long  server_socket, client_socket;
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

		printf("Accepted From Client: %ld\n", client_socket);
		// run pthread on client_socket

		Error = pthread_create(&threadID, NULL, &eventAction, (void *)client_socket );
		if (Error != 0)
			printf("Error creating thread\n");
	}
	pthread_exit(NULL);
	return 0;

}

void *eventAction(void *args){
	
	
	long client_socket = (long)args;
	char  buffer[256] = {0};
	int bytesReceived = 0;
	printf(" On thread : %ld \n", client_socket);
	while(true)
	{
		//read from socket
		//printf("Entered eventAction : \n");
			
		recv(client_socket, buffer, sizeof(buffer), 0);
			
		printf("%s",buffer);
		char* cmd_str;
    	size_t cmd_len;
		cmd_len = 50;
	    cmd_str = (char*)malloc(cmd_len);
	    sprintf(cmd_str,"set key 0 900 5\r\nvalue");

	    // parse command
	    parse_command(cmd_str,cmd_len);

	    free(cmd_str);
		send(client_socket, "Test Send", sizeof("TEst Send"), 0);
		
		
		//action on command
	}	
}
