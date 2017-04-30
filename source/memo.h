#ifndef __MEMO_H_
#define __MEMO_H_

#include <string>
#include <cstdint>
#include <unordered_map>

#include "slabsalloc.h"
#include "mmapheap.h"

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
    // storage command responses 
    STORED,
    EXISTS,
    NOT_FOUND,
    // retrieval command responses
    VALUE,
    END,
    // deletion 
    // incr/decr
    DELETED,
    // touch
    TOUCHED

} RESPONSE;


const auto HeapSize = 1024UL * 1024 * 1024;
const auto SecondsIn30Days =  60 * 60 * 24 * 30;
class HeapType : public SlabsAlloc<MmapHeap<HeapSize>> {};

static HeapType& getHeap() {
    static char theHeapBuf[sizeof(HeapType)];
    static HeapType * h = new (theHeapBuf) HeapType;
    return *h;
}

namespace  Memo
{

    Header* get(std::string key);
    
    Header* gets(std::string key);
    
    RESPONSE set(std::string key, uint16_t flags, int32_t expiration_time, size_t size, std::string value, bool cas);
    
    RESPONSE add(std::string key, uint16_t flags, int32_t expiration_time, size_t size, std::string value);
    
    RESPONSE replace(std::string key, uint16_t flags, int32_t expiration_time, size_t size, std::string value, bool cas);

    RESPONSE append(std::string key, size_t size, std::string value);
    void prepend(std::string key, size_t size, std::string value);
    void mem_delete(std::string key);
    void incr(std::string key, std::string value);
    void decr(std::string key, std::string value);
    void stats();
    void flush_all(int32_t exptime);
    void version(); 
}


#endif // __MEMO_H_
