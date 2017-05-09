//
// Created by Vinitra Ramasubramaniam on 5/8/17.
//
#ifndef MEMO_STRING_CONSTANTS_H_
#define MEMO_STRING_CONSTANTS_H_

#define MEM_VERSION "1.0.0"
#define NUM_COMMANDS 15
#define NUM_RESPONSES 12

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


typedef enum
{
    // error strings
    ERROR=0,
    CLIENT_ERROR,
    SERVER_ERROR,
    STORED,
    EXISTS,
    NOT_FOUND,
    NOT_STORED,
    VALUE,
    END,
    DELETED,
    OK,
    VERSION_STR

} RESPONSE;

struct RESPONSE_STRING_MAP
{
    RESPONSE rsp;
    char* res_str;
};

inline RESPONSE_STRING_MAP RESPONSE_MAP[NUM_RESPONSES]
{
    {ERROR,(char*)"ERROR"},
    {CLIENT_ERROR,(char*)"CLIENT_ERROR"},
    {SERVER_ERROR,(char*)"SERVER_ERROR"},
    {STORED,(char*)"STORED"},
    {EXISTS,(char*)"EXISTS"},
    {NOT_FOUND,(char*)"NOT_FOUND"},
    {NOT_STORED,(char*)"NOT_STORED"},
    {VALUE,(char*)"VALUE"},
    {END,(char*)"END"},
    {DELETED,(char*)"DELETED"},
    {OK,(char*)"OK"},
    {VERSION_STR, (char*)"VERSION"}
};

struct COMMAND_STRING_MAP
{
    COMMAND cmd;
    char* cmd_str;
};

inline COMMAND_STRING_MAP CMD_MAP[NUM_COMMANDS]
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
#endif //MEMO_STRING_CONSTANTS_H
