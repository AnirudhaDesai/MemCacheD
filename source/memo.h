#ifndef __MEMO_H_
#define __MEMO_H_

#include <string>
#include <cstdint>
#include <unordered_map>
#include <cstring>
#include <stdlib.h>
#include <limits.h>
#include <exception>
#include <mutex>
#include <thread>

#include "time.h"
#include "slabsalloc.h"

const auto SecondsIn30Days =  60 * 60 * 24 * 30;

/*class HeapType : public SlabsAlloc {};*/

//static HeapType& getHeap() {
    //static char theHeapBuf[sizeof(HeapType)];
    //static HeapType * h = new (theHeapBuf) HeapType;
    //return *h;
//}

namespace  Memo
{

    Header* get(std::string key, bool isStatsChanged=false);
    
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
}


#endif // __MEMO_H_
