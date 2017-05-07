#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

#include <sys/socket.h>
#include <sys/types.h>

#include <unistd.h>

#include <netinet/in.h>
#include <pthread.h>
#include "command_parser.h"

int initializeServer();
void *beginConnect(void *args);