#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <unistd.h>

#include <netinet/in.h>
#include <pthread.h>

int initializeServer();
void *eventAction(void *args);
