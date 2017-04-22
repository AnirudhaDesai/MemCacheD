#include "command_parser.h"

void parse_command(char* cmd_str, size_t cmd_len)
{
    if(cmd_len <=0
    || cmd_str == nullptr)
    {
        return;
    }

    char *p = strtok(cmd_str, "\r\n");

    while (p)
    {
        printf ("token = %s\n", p);
        p = strtok(NULL, "\r\n");
    }
}
