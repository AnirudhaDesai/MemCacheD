#ifndef __MEMO_H_
#define __MEMO_H_

#include <string>
#include <cstdint>
#include <unordered_map>

#include "slabsalloc.h"
#include "mmapheap.h"

/*struct Header
{
    int flags;
};*/

const auto HeapSize = 1024UL * 1024 * 1024;
class HeapType : public SlabsAlloc<MmapHeap<HeapSize>> {};

static HeapType& getHeap() {
    static char theHeapBuf[sizeof(HeapType)];
    static HeapType * h = new (theHeapBuf) HeapType;
    return *h;
}

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
        printf("called %s\n",__FUNCTION__);

        printf("adding %s\n",key.c_str());
        getHeap().malloc(0);

    }


    Header* replace(std::string key)
    {
        // do stuff
    }
}



#endif // __MEMO_H_
