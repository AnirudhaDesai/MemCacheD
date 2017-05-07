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
#include <functional>

#include "Trace.h"
#include "server.h"

ALG_T cache_replacement_algorithm = LRU;

extern SlabsAlloc* alloc;

int main(int argc, char *argv[])
{
    // parse command line args

    int lru_flag = 0;
    int rnd_flag = 0;
    int lndlrd_flag = 0;
    size_t max_heap_size = 0;

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
        while (option_index < argc)
        {
            switch(option_index)
            {
                case 1:
                    char* option_str = argv[option_index];
                    //strcpy(option_str,argv[option_index]);
                    char* cache_size_str = strtok(option_str,"M");
                    short cache_size = atoi(cache_size_str);
                    if(cache_size <= 0)
                    {
                        TRACE_ERROR("invalid cache size specified");
                        return 1;
                    }

                    max_heap_size = cache_size*1024*1024;
                    TRACE_DEBUG("cache size(bytes) = ",max_heap_size); 
                    break;
            }
            option_index++;
        }
    }

    std::cout << "cache replacement algorithm :" << cache_replacement_algorithm << std::endl;

    alloc = new SlabsAlloc(cache_replacement_algorithm,max_heap_size);

    char* cmd_str;
    size_t cmd_len;

    initializeServer();
    
    return 0;
}
