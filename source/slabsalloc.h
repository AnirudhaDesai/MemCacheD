#ifndef SLABSALLOC_H
#define SLABSALLOC_H

#include <cassert>
#include <functional>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <new>
#include <mutex>
#include <sys/mman.h>
#include <stdint.h>
#include <time.h>
#include <random>
#include <unistd.h>
#include <thread>

#include "stats.h"
#include "Trace.h"

using namespace std;

#define CLASS_LIM   1024  //limit on number of objects per size class
#define NUM_CLASSES 23

//Different eviction algorithms
typedef enum {
    LRU=0,
    RANDOM,
    LANDLORD
} ALG_T;

//Header tagged with each object.
class Header {
    public:
        char key[251];
        size_t data_size;
        uint16_t flags;
        int32_t expiration_time;
        time_t expiration_timestamp;
        time_t insertedTimestamp;
        std::thread::id last_updated_client;
        int64_t cas_unique;
        
        double landlordCost; //for landlord replacement algorithm


        Header * prev;
        Header * next;
};

class SlabsAlloc {
    public:
        SlabsAlloc(ALG_T algorithm, size_t max_heap_size)
            : MAX_ALLOC(max_heap_size),
            allocated (0),
            algorithm(algorithm)

    {
        for (auto& f : freedObjects) {
            f = nullptr;
        }
        for (auto& f : head_AllocatedObjects) {
            f = nullptr;
        }
        for (auto& f : tail_AllocatedObjects) {
            f = nullptr;
        }
        for (auto& f : AllocatedCount) {
            f = 0;
        }
        TRACE_DEBUG("MAX_ALLOC=",MAX_ALLOC);

    }

        ~SlabsAlloc()
        {
        }

        enum { Alignment = 16 };


        //allocates memore and stores the object. Also handles eviction incase the class is full.
        void * store(size_t sz, Header *& evictedObject);

        //remove objects and add to freed objects
        void remove(void * ptr);

        /*Rearanges objects by pushing most recently used objects to the tail so that
         *heads always contain the objects that are meant for eviction in LRU.
         */
        void updateRecentlyUsed(Header* h);

        //(Updates with data or rearanges objects ) in a manner that will help eviction. 
        void cacheReplacementUpdates(Header* h);
        Header* getFirstObject(int i);

        // number of bytes currently allocated  
        size_t bytesAllocated();

        ALG_T algorithm;

        // Return maximum size of object for a given size class.
        static size_t getSizeFromClass(int index);

        // Return the size class for a given size.
        static int getSizeClass(size_t sz);

    private:

        recursive_mutex heapLock;

        size_t MAX_ALLOC;
        size_t allocated;
        
        uint16_t rndNum;
        std::random_device rd;

        uint16_t AllocatedCount[NUM_CLASSES];
        recursive_mutex slabLock[NUM_CLASSES];
        Header * head_AllocatedObjects[NUM_CLASSES];
        Header * tail_AllocatedObjects[NUM_CLASSES];
        Header * freedObjects[NUM_CLASSES];

};

extern "C" {
    void reportStats();
    void walk(const std::function< void(Header *) >& f);
}


#endif
