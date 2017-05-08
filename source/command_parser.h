#ifndef __CMD_PARSER_H_
#define __CMD_PARSER_H_

#include <cstdlib>
#include <cstdio>
#include <cstring>

#include "memo.h"

typedef enum struct PARSE_ERROR
{
    NONE=0,
    NEED_MORE_DATA=1,
    QUIT=2
};

PARSE_ERROR parse_command(std::string&, char*& res_str, size_t* res_len);


#endif // __CMD_PARSER_H_
