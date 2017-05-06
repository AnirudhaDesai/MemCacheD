#include "command_parser.h"

#include <string>

#define MAX_CMD_LINES 10
#define NUM_COMMANDS 15

#define NUM_RESPONSES 10
struct RESPONSE_STRING_MAP
{
    RESPONSE rsp;
    char* res_str;
};

RESPONSE_STRING_MAP RESPONSE_MAP[NUM_RESPONSES]
{
    // error strings
    {ERROR,(char*)"ERROR"},
    {CLIENT_ERROR,(char*)"CLIENT_ERROR"},
    {SERVER_ERROR,(char*)"SERVER_ERROR"},
    // storage command responses 
    {STORED,(char*)"STORED"},
    {EXISTS,(char*)"EXISTS"},
    {NOT_FOUND,(char*)"NOT_FOUND"},
    // retrieval command responses
    {END,(char*)"END"},
    // deletion 
    // incr/decr
    {DELETED,(char*)"DELETED"},
    {NOT_FOUND,(char*)"NOT_FOUND"}
};



void handle_set(char* cmd_lines[MAX_CMD_LINES], char*& response_str, size_t* response_len);
void handle_add(char* cmd_lines[MAX_CMD_LINES],char*& response_str, size_t* response_len);
void handle_replace(char* cmd_lines[MAX_CMD_LINES], char*& response_str, size_t* response_len);
void handle_append(char* cmd_lines[MAX_CMD_LINES], char*& response_str, size_t* response_len);
void handle_prepend(char* cmd_lines[MAX_CMD_LINES], char*& response_str, size_t* response_len);
void handle_cas(char* cmd_lines[MAX_CMD_LINES], char*& response_str, size_t* response_len);
void handle_get(char* cmd_lines[MAX_CMD_LINES], char*& response_str, size_t* response_len);
void handle_gets(char* cmd_lines[MAX_CMD_LINES], char*& response_str, size_t* response_len);
void handle_delete(char* cmd_lines[MAX_CMD_LINES], char*& response_str, size_t* response_len);
void handle_incr(char* cmd_lines[MAX_CMD_LINES], char*& response_str, size_t* response_len);
void handle_decr(char* cmd_lines[MAX_CMD_LINES], char*& response_str, size_t* response_len);
void handle_stats(char* cmd_lines[MAX_CMD_LINES], char*& response_str, size_t* response_len);
void handle_flush_all(char* cmd_lines[MAX_CMD_LINES], char*& response_str, size_t* response_len);
void handle_version(char* cmd_lines[MAX_CMD_LINES], char*& response_str, size_t* response_len);
void handle_quit(char* cmd_lines[MAX_CMD_LINES], char*& response_str, size_t* response_len);

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

void parse_command(char* cmd_str, size_t cmd_len, char*& res_str, size_t* res_len)
{

    if(cmd_len <=0
            || cmd_str == nullptr)
    {
        return;
    }

    std::string response;

    // start by storing all command lines in an array
    char* cmd_lines[MAX_CMD_LINES];
    cmd_lines[0] = strtok(cmd_str, "\\r\\n");

    unsigned short cmd_num = 0;

    while (cmd_num < MAX_CMD_LINES)
    {
        cmd_lines[++cmd_num] = strtok(NULL, "\\r\\n");
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
            handle_set(cmd_lines, res_str, res_len);
            break;
        case ADD:
            handle_add(cmd_lines, res_str, res_len);
            break;
        case REPLACE:
            handle_replace(cmd_lines, res_str, res_len);
            break;
        case APPEND:
            handle_append(cmd_lines, res_str, res_len);
            break;
        case PREPEND:
            handle_prepend(cmd_lines, res_str, res_len);
            break;
        case CAS:
            handle_cas(cmd_lines, res_str, res_len);
            break;
            // Retrieval commands
        case GET:
            handle_get(cmd_lines, res_str, res_len);
            break;
        case GETS:
            handle_gets(cmd_lines, res_str, res_len);
            break;
        case DELETE:
            handle_delete(cmd_lines, res_str, res_len);
            break;
        case INCR:
            handle_incr(cmd_lines, res_str, res_len);
            break;
        case DECR:
            handle_decr(cmd_lines, res_str, res_len);
            break;
            // Stats commands
        case STATS:
            handle_stats(cmd_lines, res_str, res_len);
            break;
            // Misc commands
        case FLUSH_ALL:
            handle_flush_all(cmd_lines, res_str, res_len);
            break;
        case VERSION:
            handle_version(cmd_lines, res_str, res_len);
            break;
        case QUIT:
            handle_quit(cmd_lines, res_str, res_len);
            break;
        case NONE:
            // do nothing
            break;
    }
}

void handle_set(char* cmd_lines[MAX_CMD_LINES], char*& response_str, size_t* response_len)
{
    // parse the rest of the first line
    char* key = strtok(NULL," ");
    uint16_t flags  = atoi((char*)strtok(NULL," "));
    int32_t expiration_time  = atoi((char*)strtok(NULL," "));
    size_t size = atoi((char*)strtok(NULL," "));
    char* value  = cmd_lines[1];
    //char* noreply = strtok(NULL, " ");

    //printf("setting key=%s,flags=%d,exptime=%s,size=%s\n",key,flags,expiration_time,size);
    printf("setting key=%s\n",key);

    RESPONSE res = Memo::set(std::string(key), flags, expiration_time, size, std::string(value), false);

    response_str = (char*)malloc(strlen(RESPONSE_MAP[res].res_str) + strlen("\r\n"));

    strcpy(response_str, RESPONSE_MAP[res].res_str);
    strcat(response_str, "\r\n");
    *response_len = strlen(response_str);


}

void handle_add(char* cmd_lines[MAX_CMD_LINES],char*& response_str, size_t* response_len)
{
    // parse the rest of the first line
    char* key = strtok(NULL," ");
    uint16_t flags  = atoi((char*)strtok(NULL," "));
    int32_t expiration_time  = atoi((char*)strtok(NULL," "));
    size_t size = atoi((char*)strtok(NULL," "));
    char* noreply = (char*)strtok(NULL," ");
    char* value  = cmd_lines[1];


    printf("handle_add,%s",key);
    //printf("setting key=%s,flags=%d,exptime=%s,bytes=%s\n",key,flags,exptime,bytes);

    RESPONSE res = Memo::add(std::string(key), flags, expiration_time, size, std::string(value));

    response_str = (char*)malloc(strlen(RESPONSE_MAP[res].res_str) + strlen("\r\n"));

    strcpy(response_str,RESPONSE_MAP[res].res_str);
    strcat(response_str,"\r\n");
    *response_len = strlen(response_str);
}

void handle_replace(char* cmd_lines[MAX_CMD_LINES], char*& response_str, size_t* response_len)
{
    // parse the rest of the first line
    char* key = strtok(NULL," ");
    uint16_t flags  = atoi((char*)strtok(NULL," "));
    int32_t expiration_time  = atoi((char*)strtok(NULL," "));
    size_t size = atoi((char*)strtok(NULL," "));
    char* noreply = strtok(NULL, " ");
    char* value  = cmd_lines[1];


    //printf("setting key=%s,flags=%d,exptime=%s,bytes=%s\n",key,flags,exptime,bytes);

    RESPONSE res = Memo::replace(std::string(key), flags, expiration_time, size, std::string(value), false);

    response_str = (char*)malloc(strlen(RESPONSE_MAP[res].res_str) + strlen("\r\n"));

    strcpy(response_str, RESPONSE_MAP[res].res_str);
    strcat(response_str, "\r\n");
    *response_len = strlen(response_str);
}

void handle_append(char* cmd_lines[MAX_CMD_LINES], char*& response_str, size_t* response_len)
{
    // parse the rest of the first line
    char* key = strtok(NULL," ");
    uint16_t flags  = atoi((char*)strtok(NULL," "));
    int32_t expiration_time  = atoi((char*)strtok(NULL," "));
    size_t size = atoi((char*)strtok(NULL," "));
    char* noreply = strtok(NULL, " ");
    char* value  = cmd_lines[1];

    //printf("setting key=%s,flags=%d,exptime=%s,bytes=%s\n",key,flags,exptime,bytes);

    RESPONSE res = Memo::append(std::string(key), size, std::string(value));

    response_str = (char*)malloc(strlen(RESPONSE_MAP[res].res_str) + strlen("\r\n"));

    strcpy(response_str, RESPONSE_MAP[res].res_str);
    strcat(response_str, "\r\n");
    *response_len = strlen(response_str);
}

void handle_prepend(char* cmd_lines[MAX_CMD_LINES], char*& response_str, size_t* response_len)
{
    // parse the rest of the first line
    char* key = strtok(NULL," ");
    uint16_t flags  = atoi((char*)strtok(NULL," "));
    int32_t expiration_time  = atoi((char*)strtok(NULL," "));
    size_t size = atoi((char*)strtok(NULL," "));
    char* noreply = strtok(NULL, " ");
    char* value  = cmd_lines[1];

    //printf("setting key=%s,flags=%d,exptime=%s,bytes=%s\n",key,flags,exptime,bytes);

    RESPONSE res = Memo::prepend(std::string(key), size, std::string(value));

    response_str = (char*)malloc(strlen(RESPONSE_MAP[res].res_str) + strlen("\r\n"));

    strcpy(response_str, RESPONSE_MAP[res].res_str);
    strcat(response_str, "\r\n");
    *response_len = strlen(response_str);
}

void handle_cas(char* cmd_lines[MAX_CMD_LINES], char*& response_str, size_t* response_len)
{
    // parse the rest of the first line
    char* key = strtok(NULL," ");
    uint16_t flags  = atoi((char*)strtok(NULL," "));
    int32_t expiration_time  = atoi((char*)strtok(NULL," "));
    size_t size = atoi((char*)strtok(NULL," "));
    char* noreply = strtok(NULL, " ");
    char* value  = cmd_lines[1];

    //printf("setting key=%s,flags=%d,exptime=%s,bytes=%s\n",key,flags,exptime,bytes);

    Memo::set(std::string(key), flags, expiration_time, size, std::string(value), true);
}

void handle_get(char* cmd_lines[MAX_CMD_LINES], char*& response_str, size_t* response_len)
{
    char* key = strtok(NULL," ");
    while(key != NULL) {
        Header* h = Memo::get(std::string(key));
        if (h != NULL) {
            printf("Get Result: %s -> %s", h->key, (char*) (h+1));
        }
        key = strtok(NULL, " ");
    }
    response_str = (char*)malloc(1);
}

void handle_gets(char* cmd_lines[MAX_CMD_LINES], char*& response_str, size_t* response_len)
{
    char* key = strtok(NULL," ");
    while(key != NULL) {
        Memo::get(std::string(key));
        key = strtok(NULL, " ");
    }
}

void handle_delete(char* cmd_lines[MAX_CMD_LINES], char*& response_str, size_t* response_len)
{
    char* key = strtok(NULL," ");
    char* noreply = strtok(NULL, " ");

    Memo::mem_delete(std::string(key));
}

void handle_incr(char* cmd_lines[MAX_CMD_LINES], char*& response_str, size_t* response_len)
{
    char* key = strtok(NULL," ");
    char* noreply = strtok(NULL, " ");
    char* value  = cmd_lines[1];

    Memo::incr(std::string(key), std::string(value));
}

void handle_decr(char* cmd_lines[MAX_CMD_LINES], char*& response_str, size_t* response_len)
{
    char* key = strtok(NULL," ");
    char* noreply = strtok(NULL, " ");
    char* value  = cmd_lines[1];

    Memo::decr(std::string(key), std::string(value));
}

void handle_stats(char* cmd_lines[MAX_CMD_LINES], char*& response_str, size_t* response_len)
{
    Memo::stats();
}

void handle_flush_all(char* cmd_lines[MAX_CMD_LINES], char*& response_str, size_t* response_len)
{
    int32_t exptime = atoi((char*) strtok(NULL, " "));
    Memo::flush_all(exptime);
}

void handle_version(char* cmd_lines[MAX_CMD_LINES], char*& response_str, size_t* response_len)
{
    Memo::version();
}

void handle_quit(char* cmd_lines[MAX_CMD_LINES], char*& response_str, size_t* response_len)
{
    // send client a command to quit
}
