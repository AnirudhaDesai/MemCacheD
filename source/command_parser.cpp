#include "command_parser.h"
#include "memo.h"

#include <string>

#define MAX_CMD_LINES 10
#define NUM_COMMANDS 15

void handle_set(char* cmd_lines[MAX_CMD_LINES]);
void handle_add(char* cmd_lines[MAX_CMD_LINES]);
void handle_replace(char* cmd_lines[MAX_CMD_LINES]);
void handle_append(char* cmd_lines[MAX_CMD_LINES]);
void handle_prepend(char* cmd_lines[MAX_CMD_LINES]);
void handle_cas(char* cmd_lines[MAX_CMD_LINES]);
void handle_get(char* cmd_lines[MAX_CMD_LINES]);
void handle_gets(char* cmd_lines[MAX_CMD_LINES]);
void handle_delete(char* cmd_lines[MAX_CMD_LINES]);
void handle_incr(char* cmd_lines[MAX_CMD_LINES]);
void handle_decr(char* cmd_lines[MAX_CMD_LINES]);
void handle_stats(char* cmd_lines[MAX_CMD_LINES]);
void handle_flush_all(char* cmd_lines[MAX_CMD_LINES]);
void handle_version(char* cmd_lines[MAX_CMD_LINES]);
void handle_quit(char* cmd_lines[MAX_CMD_LINES]);

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
            handle_add(cmd_lines);
            break;
        case REPLACE:
            handle_replace(cmd_lines);
            break;
        case APPEND:
            handle_append(cmd_lines);
            break;
        case PREPEND:
            handle_prepend(cmd_lines);
            break;
        case CAS:
            handle_cas(cmd_lines);
            break;
            // Retrieval commands
        case GET:
            handle_get(cmd_lines);
            break;
        case GETS:
            handle_gets(cmd_lines);
            break;
        case DELETE:
            handle_delete(cmd_lines);
            break;
        case INCR:
            handle_incr(cmd_lines);
            break;
        case DECR:
            handle_decr(cmd_lines);
            break;
            // Stats commands
        case STATS:
            handle_stats(cmd_lines);
            break;
            // Misc commands
        case FLUSH_ALL:
            handle_flush_all(cmd_lines);
            break;
        case VERSION:
            handle_version(cmd_lines);
            break;
        case QUIT:
            handle_quit(cmd_lines);
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
    uint16_t flags  = atoi((char*)strtok(NULL," "));
    int32_t expiration_time  = atoi((char*)strtok(NULL," "));
    size_t size = atoi((char*)strtok(NULL," "));
    char* value  = strtok(NULL," ");
    char* noreply = strtok(NULL, " ");

    //printf("setting key=%s,flags=%d,exptime=%s,bytes=%s\n",key,flags,exptime,bytes);

    Memo::set(std::string(key), flags, expiration_time, size, std::string(value), false);
}

void handle_add(char* cmd_lines[MAX_CMD_LINES])
{
    // parse the rest of the first line
    char* key = strtok(NULL," ");
    uint16_t flags  = atoi((char*)strtok(NULL," "));
    int32_t expiration_time  = atoi((char*)strtok(NULL," "));
    size_t size = atoi((char*)strtok(NULL," "));
    char* value  = strtok(NULL," ");
    char* noreply = strtok(NULL, " ");

    //printf("setting key=%s,flags=%d,exptime=%s,bytes=%s\n",key,flags,exptime,bytes);

    Memo::add(std::string(key), flags, expiration_time, size, std::string(value));
}

void handle_replace(char* cmd_lines[MAX_CMD_LINES])
{
    // parse the rest of the first line
    char* key = strtok(NULL," ");
    uint16_t flags  = atoi((char*)strtok(NULL," "));
    int32_t expiration_time  = atoi((char*)strtok(NULL," "));
    size_t size = atoi((char*)strtok(NULL," "));
    char* value  = strtok(NULL," ");
    char* noreply = strtok(NULL, " ");


    //printf("setting key=%s,flags=%d,exptime=%s,bytes=%s\n",key,flags,exptime,bytes);

    Memo::replace(std::string(key), flags, expiration_time, size, std::string(value), false);
}

void handle_append(char* cmd_lines[MAX_CMD_LINES])
{
    // parse the rest of the first line
    char* key = strtok(NULL," ");
    uint16_t flags  = atoi((char*)strtok(NULL," "));
    int32_t expiration_time  = atoi((char*)strtok(NULL," "));
    size_t size = atoi((char*)strtok(NULL," "));
    char* value  = strtok(NULL," ");
    char* noreply = strtok(NULL, " ");

    //printf("setting key=%s,flags=%d,exptime=%s,bytes=%s\n",key,flags,exptime,bytes);

    Memo::append(std::string(key), size, std::string(value));
}

void handle_prepend(char* cmd_lines[MAX_CMD_LINES])
{
    // parse the rest of the first line
    char* key = strtok(NULL," ");
    uint16_t flags  = atoi((char*)strtok(NULL," "));
    int32_t expiration_time  = atoi((char*)strtok(NULL," "));
    size_t size = atoi((char*)strtok(NULL," "));
    char* value  = strtok(NULL," ");
    char* noreply = strtok(NULL, " ");

    //printf("setting key=%s,flags=%d,exptime=%s,bytes=%s\n",key,flags,exptime,bytes);

    Memo::prepend(std::string(key), size, std::string(value));
}

void handle_cas(char* cmd_lines[MAX_CMD_LINES])
{
    // parse the rest of the first line
    char* key = strtok(NULL," ");
    uint16_t flags  = atoi((char*)strtok(NULL," "));
    int32_t expiration_time  = atoi((char*)strtok(NULL," "));
    size_t size = atoi((char*)strtok(NULL," "));
    char* value  = strtok(NULL," ");
    char* noreply = strtok(NULL, " ");

    //printf("setting key=%s,flags=%d,exptime=%s,bytes=%s\n",key,flags,exptime,bytes);

    Memo::set(std::string(key), flags, expiration_time, size, std::string(value), true);
}

void handle_get(char* cmd_lines[MAX_CMD_LINES])
{
    char* key = strtok(NULL," ");
    while(key != NULL) {
        key = strtok(NULL, " ");
        Memo::get(std::string(key));
    }
}

void handle_gets(char* cmd_lines[MAX_CMD_LINES])
{
    char* key = strtok(NULL," ");
    while(key != NULL) {
        key = strtok(NULL, " ");
        Memo::get(std::string(key));
    }
}

void handle_delete(char* cmd_lines[MAX_CMD_LINES])
{
    char* key = strtok(NULL," ");
    char* noreply = strtok(NULL, " ");

    Memo::mem_delete(std::string(key));
}

void handle_incr(char* cmd_lines[MAX_CMD_LINES])
{
    char* key = strtok(NULL," ");
    char* value= strtok(NULL," ");
    char* noreply = strtok(NULL, " ");

    Memo::incr(std::string(key), std::string(value));
}

void handle_decr(char* cmd_lines[MAX_CMD_LINES])
{
    char* key = strtok(NULL," ");
    char* value= strtok(NULL," ");
    char* noreply = strtok(NULL, " ");

    Memo::decr(std::string(key), std::string(value));
}

void handle_stats(char* cmd_lines[MAX_CMD_LINES])
{
    Memo::stats();
}

void handle_flush_all(char * cmd_lines[MAX_CMD_LINES])
{
    int32_t exptime = atoi((char*) strtok(NULL, " "));
    Memo::flush_all(exptime);
}

void handle_version(char * cmd_lines[MAX_CMD_LINES])
{
    Memo::version();
}

void handle_quit(char * cmd_lines[MAX_CMD_LINES])
{
    // send client a command to quit
}