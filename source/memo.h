#ifndef __MEMO_H_
#define __MEMO_H_

#include <string>
#include <cstdint>
#include <unordered_map>

#include "slabsalloc.h"

/*struct Header
{
    int flags;
};*/

namespace  Memo
{
    std::unordered_map<std::string, Header*> Table;


    Header* get(std::string key)
    {
        std::unordered_map<std::string,Header*>::const_iterator got = Table.find (key);
        if ( got == Table.end() )
        {
            std::cout << "not found" << std::endl;
            return nullptr;
        }
        else
        {
            //std::cout << got->first << " is " << got->second->flags << std::endl;
            return got->second;
        }
    }

    Header* add(std::string key)
    {
        // do stuff
    }


    Header* replace(std::string key)
    {
        // do stuff
    }
}



#endif // __MEMO_H_
