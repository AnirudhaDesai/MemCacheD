#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <iostream>
#include <string.h>
#include <cstdlib>

#include <netinet/in.h>

#include <unistd.h>

using namespace std;

int main() {
	// create a socket
	int network_socket;
	char server_message[] = "SS";
	network_socket = socket(AF_INET, SOCK_STREAM, 0);

	// specify an address for the socket
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY;

	int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
	if (connection_status == -1)
		printf("There was an error making a connection\n\n"); 

	//receive data from the server
	char server_response[256];
	
	printf("Starting Send \n");
	//send(network_socket	, "SSSSS", sizeof("SSSSS"), 0);
	printf("End of Send.. \n"); 
	
	//recv(network_socket, &server_response, sizeof(server_response), 0);
	

	// print out the response
	printf("the server sent the data:  %s\n", server_response);

	while(true){
		std::cout<<"Enter next command : \n";
		std::fgets(server_response, 256, stdin);
		send(network_socket	, server_response, sizeof(server_response), 0);
	}

	// close the sockett
	close(network_socket);
	return 0;
}
