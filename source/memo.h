#ifndef __MEMO_H_
#define __MEMO_H_

#include <string>
#include <cstdint>
#include <unordered_map>

#include "slabsalloc.h"

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
    INCREMENTED,
    DECREMENTED,
    DELETED

} RESPONSE;

const auto SecondsIn30Days =  60 * 60 * 24 * 30;

/*class HeapType : public SlabsAlloc {};*/

//static HeapType& getHeap() {
    //static char theHeapBuf[sizeof(HeapType)];
    //static HeapType * h = new (theHeapBuf) HeapType;
    //return *h;
//}

namespace  Memo
{

    Header* get(std::string key, const char * callerFunction);
    
    Header* gets(std::string key);
    
    RESPONSE set(std::string key, uint16_t flags, int32_t expiration_time, size_t size, std::string value, bool cas=false);
    
    RESPONSE add(std::string key, uint16_t flags, int32_t expiration_time, size_t size, std::string value, bool updateExpirationTime=true);
    
    RESPONSE replace(std::string key, uint16_t flags, int32_t expiration_time, size_t size, std::string value, bool cas=false, bool updateExpirationTime=true);

    RESPONSE append(std::string key, size_t size, std::string value);
    RESPONSE prepend(std::string key, size_t size, std::string value);
    Header* incr(std::string key, std::string value);
    Header* decr(std::string key, std::string value);
    RESPONSE mem_delete(std::string key);
    void stats(char*& response_str, size_t* response_len);
    void flush_all(int32_t exptime);
    void version(); 
}


#endif // __MEMO_H_
