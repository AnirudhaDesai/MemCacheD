/*
 * 630 Systems Assignment 4
 * Memo - A Data Caching Service
 * Team : Team Awesome
 * Members : Vikram Anirudha Vinithra Shruthi
 *
 */

/*
   m                                                                         
 mm#mm   mmm    mmm   mmmmm   mmm  m     m  mmm    mmm    mmm   mmmmm   mmm  
   #    #"  #  "   #  # # #  "   # "m m m" #"  #  #   "  #" "#  # # #  #"  # 
   #    #""""  m"""#  # # #  m"""#  #m#m#  #""""   """m  #   #  # # #  #"""" 
   "mm  "#mm"  "mm"#  # # #  "mm"#   # #   "#mm"  "mmm"  "#m#"  # # #  "#mm" 
 *
 */


#include <iostream>

#include "command_parser.h"

int main(int argc, char *argv[])
{
    char* cmd_str;
    size_t cmd_len;

    //while(1)
    //{
        // listen on port 
        //
        // read command
        cmd_len = 50;
        cmd_str = (char*)malloc(cmd_len);
        sprintf(cmd_str,"set key 0 900 5\r\nvalue");

        // parse command
        parse_command(cmd_str,cmd_len);

        free(cmd_str);
    //}

    return 0;
}
