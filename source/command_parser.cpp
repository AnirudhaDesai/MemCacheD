#include "command_parser.h"

#define MAX_CMD_LINES 10
#define NUM_COMMANDS 15

void handle_set(char* cmd_lines[MAX_CMD_LINES]);

typedef enum {
    SET =0,
    ADD ,
    REPLACE ,
    APPEND ,
    PREPEND ,
    CAS ,
    // Retrieval commands
    GET ,
    GETS ,
    DELETE ,
    INCR ,
    DECR ,
    // Stats commands
    STATS ,
    // Misc commands
    FLUSH_ALL ,
    VERSION ,
    QUIT,
    NONE
} COMMAND;

struct COMMAND_STRING_MAP
{
    COMMAND cmd;
    char* cmd_str;
};

COMMAND_STRING_MAP CMD_MAP[NUM_COMMANDS]
{
    { SET, (char*)"set" },
    { ADD, (char*)"add" },
    { REPLACE, (char*)"replace" },
    { APPEND, (char*)"append" },
    { PREPEND, (char*)"prepend" },
    { CAS, (char*)"cas" },
    { GET, (char*)"get" },
    { GETS, (char*)"gets" },
    { DELETE, (char*)"delete" },
    { INCR, (char*)"incr" },
    { DECR, (char*)"decr" },
    { STATS, (char*)"stats" },
    { FLUSH_ALL, (char*)"flush_all" },
    { VERSION, (char*)"version" },
    { QUIT, (char*)"quit" },
};

void parse_command(char* cmd_str, size_t cmd_len)
{

    if(cmd_len <=0
            || cmd_str == nullptr)
    {
        return;
    }

    // start by storing all command lines in an array
    char* cmd_lines[MAX_CMD_LINES];
    cmd_lines[0] = strtok(cmd_str, "\r\n");

    unsigned short cmd_num = 0;

    while (cmd_num < MAX_CMD_LINES)
    {
        cmd_lines[++cmd_num] = strtok(NULL, "\r\n");
    }

    // figure out the main command
    char* main_command_str = strtok(cmd_lines[0]," ");

    COMMAND command = NONE;

    for(int i=0;i<NUM_COMMANDS;i++)
    {
        if(strcmp(main_command_str,CMD_MAP[i].cmd_str)==0)
        {
            command = CMD_MAP[i].cmd;
            break;
        }
    }

    printf ("got main command = %d %s\n",command, main_command_str);

    // now handle command-specific stuff
    switch(command)
    {
        case SET:
            handle_set(cmd_lines);
            break;
        case ADD:
            break;
        case REPLACE:
            break;
        case APPEND:
            break;
        case PREPEND:
            break;
        case CAS:
            break;
            // Retrieval commands
        case GET:
            break;
        case GETS:
            break;
        case DELETE:
            break;
        case INCR:
            break;
        case DECR:
            break;
            // Stats commands
        case STATS:
            break;
            // Misc commands
        case FLUSH_ALL:
            break;
        case VERSION:
            break;
        case QUIT:
            break;
        case NONE:
            // do nothing
            break;
    }
}

void handle_set(char* cmd_lines[MAX_CMD_LINES])
{
    // parse the rest of the first line
    char* key = strtok(NULL," ");
    char* flags  = strtok(NULL," ");
    char* exptime  = strtok(NULL," ");
    char* bytes  = strtok(NULL," ");

    printf("setting key=%s,flags=%s,exptime=%s,bytes=%s\n",key,flags,exptime,bytes);
}
