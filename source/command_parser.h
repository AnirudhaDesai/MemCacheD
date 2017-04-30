#ifndef __CMD_PARSER_H_
#define __CMD_PARSER_H_

#include <cstdlib>
#include <cstdio>
#include <cstring>

#include "memo.h"

void parse_command(char* cmd_str, size_t cmd_len, char*& res_str, size_t* res_len);


#endif // __CMD_PARSER_H_
