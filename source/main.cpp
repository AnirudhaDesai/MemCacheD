/*
 * 630 Systems Assignment 4
 * Memo - A Data Caching Service
 * Team : Team Awesome
 * Members : Vikram Anirudha Vinithra Shruthi
 *
 */

#include <iostream>
#include <unistd.h>
#include <getopt.h>

#include "mmapheap.h"
#include "command_parser.h"

const auto DefaultHeapSize = 1 * 1024UL * 1024 * 1024;

typedef enum {
    LRU=0,
    RANDOM,
    LANDLORD
} ALG_T;

ALG_T cache_replacement_algorithm = LRU;

MmapHeap* heap = new MmapHeap(DefaultHeapSize);  

int main(int argc, char *argv[])
{
    // parse command line args

    int lru_flag = 0;
    int rnd_flag = 0;
    int lndlrd_flag = 0;

    struct option long_options[] =
    {
        {"lru",      no_argument, &lru_flag, 1},
        {"random",   no_argument, &rnd_flag, 1},
        {"landlord", no_argument, &lndlrd_flag, 1}
    };

    int c;
    int option_index = 0;
    c = getopt_long (argc, argv, "", long_options, &option_index);

    // set cache replacement algorithm 
    //
    if(lru_flag)
    {
        cache_replacement_algorithm = LRU;
    }
    else if(rnd_flag)
    {
        cache_replacement_algorithm = RANDOM;
    }
    else if(lndlrd_flag)
    {
        cache_replacement_algorithm = LANDLORD;
    }

    if (option_index < argc)
    {
        printf ("non-option ARGV-elements: ");
        while (option_index < argc)
            printf ("%s ", argv[option_index++]);
        printf ("\n");
    }

    std::cout << "cache replacement algorithm :" << cache_replacement_algorithm << std::endl;
    std::cout << "heap size " << (heap->getSize())/1024/1024 << std::endl;
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
