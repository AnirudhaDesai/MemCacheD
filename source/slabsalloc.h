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

using namespace std;

class Header {
 public:
  char key[251];
  size_t data_size;  
  uint16_t flags;
  int32_t expiration_time;

  Header * prev;
  Header * next;
};

template <class SourceHeap>
class SlabsAlloc : public SourceHeap {
public:
  SlabsAlloc()
    : requested (0),
      allocated (0),
      maxRequested (0),
      maxAllocated (0)
  {
    //for (auto& f : FreedObjects) {
     // f = nullptr;
   // }
    for (auto& f : head_AllocatedObjects) {
      f = nullptr;
    }
    for (auto& f : tail_AllocatedObjects) {
      f = nullptr;
    }

  }

  ~SlabsAlloc()
  {
  }
  
  enum { Alignment = 16 };
  
  void * malloc(size_t sz);
  void free(void * ptr);
  size_t getSize(void * p);

  // number of bytes currently allocated  
  size_t bytesAllocated();
  
  // max number of bytes allocated  
  size_t maxBytesAllocated();

  // number of bytes *requested*
  // (e.g., malloc(4) might result in an allocation of 8; 4 = bytes requested, 8 = bytes allocated)
  size_t bytesRequested();
  
  // max number of bytes *requested*
  size_t maxBytesRequested();

  void walk(const std::function< void(Header *) >& f); 

  // Return maximum size of object for a given size class.
  static size_t getSizeFromClass(int index);
  
  // Return the size class for a given size.
  static int getSizeClass(size_t sz);

private:

  recursive_mutex heapLock;
  
  size_t allocated;
  size_t requested;
  size_t maxAllocated;
  size_t maxRequested;
  
  Header * head_AllocatedObjects[23];
  Header * tail_AllocatedObjects[23];
  //Header * FreedObjects[23];
};

#include "slabsalloc.cpp"

extern "C" {
  void reportStats();
  void walk(const std::function< void(Header *) >& f);
}

#endif
