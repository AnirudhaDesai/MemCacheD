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

#include "mmapheap.h"
#include "command_parser.h"

const auto DefaultHeapSize = 2 * 1024UL * 1024 * 1024;

MmapHeap* heap = new MmapHeap(DefaultHeapSize);  

int main(int argc, char *argv[])
{
    // parse command line args

    for(int i=1;i<argc;i++)
    {
        printf("%s\n",argv[i]);
    }

    //std::cout << "heap size " << (heap->getSize())/1024/1024 << std::endl;
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
    //

    //while(1);

    return 0;
}
