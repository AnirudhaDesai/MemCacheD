#include "command_parser.h"

#include <string>
#include <regex>

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
    {VALUE,(char*)"VALUE"},
    {END,(char*)"END"},
    // deletion
    // incr/decr
    {DELETED,(char*)"DELETED"},
    {NOT_FOUND,(char*)"NOT_FOUND"}
};



void handle_set(std::sregex_token_iterator cmd_itr, std::sregex_token_iterator param_itr, char*& response_str, size_t* response_len);
void handle_add(std::sregex_token_iterator cmd_itr, std::sregex_token_iterator param_itr, char*& response_str, size_t* response_len);
void handle_replace(std::sregex_token_iterator cmd_itr, std::sregex_token_iterator param_itr, char*& response_str, size_t* response_len);
void handle_append(std::sregex_token_iterator cmd_itr, std::sregex_token_iterator param_itr, char*& response_str, size_t* response_len);
void handle_prepend(std::sregex_token_iterator cmd_itr, std::sregex_token_iterator param_itr, char*& response_str, size_t* response_len);
void handle_cas(std::sregex_token_iterator cmd_itr, std::sregex_token_iterator param_itr, char*& response_str, size_t* response_len);
void handle_get(std::sregex_token_iterator param_itr, char*& response_str, size_t* response_len);
void handle_gets(std::sregex_token_iterator param_itr, char*& response_str, size_t* response_len);
void handle_delete(std::sregex_token_iterator param_itr, char*& response_str, size_t* response_len);
void handle_incr(std::sregex_token_iterator cmd_itr, std::sregex_token_iterator param_itr, char*& response_str, size_t* response_len);
void handle_decr(std::sregex_token_iterator cmd_itr, std::sregex_token_iterator param_itr, char*& response_str, size_t* response_len);
void handle_stats(char*& response_str, size_t* response_len);
void handle_flush_all(std::sregex_token_iterator param_itr, char*& response_str, size_t* response_len);
void handle_version(char*& response_str, size_t* response_len);
void handle_quit(char*& response_str, size_t* response_len);

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
    std::regex ws_re("\\s+");
    std::regex end_re("\\\\r\\\\n");
    std::string cmd = std::string(cmd_str);
    // start by storing all command lines in an array
//    const const char* cmd_lines[MAX_CMD_LINES];
    std::string command_str;
    //cmd_lines[0] = strtok(cmd_str, "\\r\\n");
    std::sregex_token_iterator cmd_itr = std::sregex_token_iterator(cmd.begin(), cmd.end(), end_re, -1);
    printf("setting key=%s\n",cmd_itr->str().c_str());
    command_str = *cmd_itr++;
    std::sregex_token_iterator end_itr;

    // figure out the main command
    std::sregex_token_iterator param_itr = std::sregex_token_iterator(command_str.begin(), command_str.end(), ws_re, -1);
    string main_command_str = *param_itr++;

    COMMAND command = NONE;

    for(int i=0;i<NUM_COMMANDS;i++)
    {
        if(strcmp(main_command_str.c_str(),CMD_MAP[i].cmd_str)==0)
        {
            command = CMD_MAP[i].cmd;
            break;
        }
    }

    printf ("got main command = %d %s\n",command, main_command_str.c_str());

    // now handle command-specific stuff
    switch(command)
    {
        case SET:
            handle_set(cmd_itr, param_itr, res_str, res_len);
            break;
        case ADD:
            handle_add(cmd_itr, param_itr, res_str, res_len);
            break;
        case REPLACE:
            handle_replace(cmd_itr, param_itr, res_str, res_len);
            break;
        case APPEND:
            handle_append(cmd_itr, param_itr, res_str, res_len);
            break;
        case PREPEND:

            handle_prepend(cmd_itr, param_itr, res_str, res_len);

            break;
        case CAS:
            handle_cas(cmd_itr, param_itr, res_str, res_len);
            break;
            // Retrieval commands
        case GET:
            handle_get(param_itr, res_str, res_len);
            break;
        case GETS:
            handle_get(param_itr, res_str, res_len);
            break;
        case DELETE:
            handle_delete(param_itr, res_str, res_len);
            break;
        case INCR:
            handle_incr(cmd_itr, param_itr, res_str, res_len);
            break;
        case DECR:
            handle_decr(cmd_itr, param_itr, res_str, res_len);
            break;
            // Stats commands
        case STATS:
            handle_stats(res_str, res_len);
            break;
            // Misc commands
        case FLUSH_ALL:
            handle_flush_all(param_itr, res_str, res_len);
            break;
        case VERSION:
            handle_version(res_str, res_len);
            break;
        case QUIT:
            handle_quit(res_str, res_len);
            break;
        case NONE:
            // do nothing
            break;
    }
}

void handle_set(std::sregex_token_iterator cmd_itr, std::sregex_token_iterator param_itr, char*& response_str, size_t* response_len)
{
    // parse the rest of the first line
    std::sregex_token_iterator end_itr;
    std::string key = *param_itr++;
    std::string flags_str = *param_itr++;
    uint16_t flags  = atoi(flags_str.c_str());
    std::string expiration_time_str = *param_itr++;
    int32_t expiration_time  = atoi(expiration_time_str.c_str());
    std::string size_str = *param_itr++;
    size_t size = atoi(size_str.c_str());
    bool noreply = false;
    if (param_itr != end_itr) {
        noreply = true;
    }
    std::string value = *cmd_itr++;

    //printf("setting key=%s,flags=%d,exptime=%s,size=%s\n",key,flags,expiration_time,size);
    printf("setting key=%s\n", key.c_str());

    RESPONSE res = Memo::set(key, flags, expiration_time, size, value, false);

    response_str = (char*)malloc(strlen(RESPONSE_MAP[res].res_str) + strlen("\r\n"));

    strcpy(response_str, RESPONSE_MAP[res].res_str);
    strcat(response_str, "\r\n");
    *response_len = strlen(response_str);


}

void handle_add(std::sregex_token_iterator cmd_itr, std::sregex_token_iterator param_itr, char*& response_str, size_t* response_len)
{
    // parse the rest of the first line
    std::sregex_token_iterator end_itr;
    std::string key = *param_itr++;
    std::string flags_str = *param_itr++;
    uint16_t flags  = atoi(flags_str.c_str());
    std::string expiration_time_str = *param_itr++;
    int32_t expiration_time  = atoi(expiration_time_str.c_str());
    std::string size_str = *param_itr++;
    size_t size = atoi(size_str.c_str());
    bool noreply = false;
    if (param_itr != end_itr) {
        noreply = true;
    }
    std::string value = *cmd_itr++;


    printf("handle_add,%s",key.c_str());
    //printf("setting key=%s,flags=%d,exptime=%s,bytes=%s\n",key,flags,exptime,bytes);

    RESPONSE res = Memo::add(key, flags, expiration_time, size, value);

    response_str = (char*)malloc(strlen(RESPONSE_MAP[res].res_str) + strlen("\r\n"));

    strcpy(response_str,RESPONSE_MAP[res].res_str);
    strcat(response_str,"\r\n");
    *response_len = strlen(response_str);
}

void handle_replace(std::sregex_token_iterator cmd_itr, std::sregex_token_iterator param_itr, char*& response_str, size_t* response_len)
{
    // parse the rest of the first line
    std::sregex_token_iterator end_itr;
    std::string key = *param_itr++;
    std::string flags_str = *param_itr++;
    uint16_t flags  = atoi(flags_str.c_str());
    std::string expiration_time_str = *param_itr++;
    int32_t expiration_time  = atoi(expiration_time_str.c_str());
    std::string size_str = *param_itr++;
    size_t size = atoi(size_str.c_str());
    bool noreply = false;
    if (param_itr != end_itr) {
        noreply = true;
    }
    std::string value = *cmd_itr++;


    //printf("setting key=%s,flags=%d,exptime=%s,bytes=%s\n",key,flags,exptime,bytes);

    RESPONSE res = Memo::replace(key, flags, expiration_time, size, value, false);

    response_str = (char*)malloc(strlen(RESPONSE_MAP[res].res_str) + strlen("\r\n"));

    strcpy(response_str, RESPONSE_MAP[res].res_str);
    strcat(response_str, "\r\n");
    *response_len = strlen(response_str);
}

void handle_append(std::sregex_token_iterator cmd_itr, std::sregex_token_iterator param_itr, char*& response_str, size_t* response_len)
{
    // parse the rest of the first line
    std::sregex_token_iterator end_itr;
    std::string key = *param_itr++;
    std::string size_str = *param_itr++;
    size_t size = atoi(size_str.c_str());
    bool noreply = false;
    if (param_itr != end_itr) {
        noreply = true;
    }
    std::string value = *cmd_itr++;

    //printf("setting key=%s,flags=%d,exptime=%s,bytes=%s\n",key,flags,exptime,bytes);

    RESPONSE res = Memo::append(key, size, value);

    response_str = (char*)malloc(strlen(RESPONSE_MAP[res].res_str) + strlen("\r\n"));

    strcpy(response_str, RESPONSE_MAP[res].res_str);
    strcat(response_str, "\r\n");
    *response_len = strlen(response_str);
}

void handle_prepend(std::sregex_token_iterator cmd_itr, std::sregex_token_iterator param_itr, char*& response_str, size_t* response_len)
{
    printf("called********** %s\n",__FUNCTION__);
    // parse the rest of the first line

    std::sregex_token_iterator end_itr;
    std::string key = *param_itr++;
    std::string size_str = *param_itr++;
    size_t size = atoi(size_str.c_str());
    bool noreply = false;
    if (param_itr != end_itr) {
        noreply = true;
    }
    std::string value = *cmd_itr++;

    //printf("setting key=%s,flags=%d,exptime=%s,bytes=%s\n",key,flags,exptime,bytes);

    RESPONSE res = Memo::prepend(key, size, value);

    response_str = (char*)malloc(strlen(RESPONSE_MAP[res].res_str) + strlen("\r\n"));

    strcpy(response_str, RESPONSE_MAP[res].res_str);
    strcat(response_str, "\r\n");
    *response_len = strlen(response_str);
}

void handle_cas(std::sregex_token_iterator cmd_itr, std::sregex_token_iterator param_itr, char*& response_str, size_t* response_len)
{
    // parse the rest of the first line
    std::sregex_token_iterator end_itr;
    std::string key = *param_itr++;
    std::string flags_str = *param_itr++;
    uint16_t flags  = atoi(flags_str.c_str());
    std::string expiration_time_str = *param_itr++;
    int32_t expiration_time  = atoi(expiration_time_str.c_str());
    std::string size_str = *param_itr++;
    size_t size = atoi(size_str.c_str());
    bool noreply = false;
    if (param_itr != end_itr) {
        noreply = true;
    }
    std::string value = *cmd_itr++;

    //printf("setting key=%s,flags=%d,exptime=%s,bytes=%s\n",key,flags,exptime,bytes);

    Memo::set(key, flags, expiration_time, size, value, true);
}

void handle_get(std::sregex_token_iterator param_itr, char*& response_str, size_t* response_len)
{

    char* single_response_str = nullptr;
    response_str = nullptr;
    *response_len = 0;
    std::sregex_token_iterator end_itr;

    std::string key;
    do {
        key = *(param_itr++);
        
        Header* h = Memo::get(key,__FUNCTION__);
        if (h != NULL)
        {
            printf("Get Result: key=%s, data_size=%u, flags=%u", h->key,h->data_size,h->flags);
            //printf("Get Result: key=%s, data_size=%u, flags=%u", h->key,h->data_size,h->flags, (char*) (h+1));
            if(response_str == nullptr)
            {
                response_str = (char*)calloc(1,strlen(RESPONSE_MAP[VALUE].res_str));
            }
            else
            {
                response_str = (char*)realloc(response_str,std::strlen(response_str)+std::strlen(RESPONSE_MAP[VALUE].res_str)+1);

            }
            std::strcat(response_str,RESPONSE_MAP[VALUE].res_str);
            response_str = (char*)realloc(response_str,std::strlen(response_str)+1);
            std::strcat(response_str," ");
            response_str = (char*)std::realloc(response_str, std::strlen(response_str)+std::strlen(key.c_str()));
            std::strcat(response_str, key.c_str());
            response_str = (char*)realloc(response_str,std::strlen(response_str)+1);
            std::strcat(response_str," ");
            char flags_str[20];
            sprintf(flags_str,"%u",h->flags);
            response_str = (char*)realloc(response_str, std::strlen(response_str)+std::strlen(flags_str));
            std::strcat(response_str,flags_str);
            response_str = (char*)realloc(response_str,std::strlen(response_str)+1);
            std::strcat(response_str," ");
            char data_size_str[20];
            sprintf(data_size_str,"%u",h->data_size);
            response_str = (char*)realloc(response_str, std::strlen(response_str)+std::strlen(data_size_str));
            std::strcat(response_str,data_size_str);
            response_str = (char*)realloc(response_str,std::strlen(response_str)+4);
            std::strcat(response_str,"\r\n");
            response_str = (char*)realloc(response_str,std::strlen(response_str)+h->data_size);
            std::strncat(response_str,(char*)(h+1),h->data_size);
            response_str = (char*)realloc(response_str,std::strlen(response_str)+4);
            std::strcat(response_str,"\r\n");
        }
    } while(param_itr != end_itr);
    *response_len = strlen(response_str);
}

void handle_delete(std::sregex_token_iterator param_itr, char*& response_str, size_t* response_len)
{
    std::sregex_token_iterator end_itr;
    std::string key = *param_itr++;
    bool noreply = false;
    if (param_itr != end_itr) {
        noreply = true;
    }

    Memo::mem_delete(key);
}

void handle_incr(std::sregex_token_iterator cmd_itr, std::sregex_token_iterator param_itr, char*& response_str, size_t* response_len)
{
    std::sregex_token_iterator end_itr;
    std::string key = *(param_itr++);
    bool noreply = false;
    if (param_itr != end_itr) {
        noreply = true;
    }
    std::string value = *cmd_itr++;

    Memo::incr(key, value);
}

void handle_decr(std::sregex_token_iterator cmd_itr, std::sregex_token_iterator param_itr, char*& response_str, size_t* response_len)
{
    std::sregex_token_iterator end_itr;
    std::string key = *(param_itr++);
    bool noreply = false;
    if (param_itr != end_itr) {
        noreply = true;
    }
    std::string value = *cmd_itr++;

    Memo::decr(key, value);
}

void handle_stats(char*& response_str, size_t* response_len)
{
    Memo::stats();
}

void handle_flush_all(std::sregex_token_iterator param_itr, char*& response_str, size_t* response_len)
{
    std::sregex_token_iterator end_itr;
    std::string expiration_time_str = *param_itr++;
    int32_t expiration_time  = atoi(expiration_time_str.c_str());
    Memo::flush_all(expiration_time);
}

void handle_version(char*& response_str, size_t* response_len)
{
    Memo::version();
}

void handle_quit(char*& response_str, size_t* response_len)
{
    // send client a command to quit
    response_str = (char*)malloc(std::strlen("QUIT\r\n"));
    std::strcpy(response_str, (char*) "QUIT\r\n");
    *response_len = std::strlen(response_str);
}
