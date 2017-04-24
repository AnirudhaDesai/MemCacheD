#include "slabsalloc.h"

template <class SourceHeap>
void * SlabsAlloc<SourceHeap>::malloc(size_t sz) {
  
  Header *h;

  /*size will contain the closest base 16 size that needs to be alocated.*/
  int i = getSizeClass(sz);
  size_t size = getSizeFromClass(i);  
  
  heapLock.lock();
  /* Check in freedObjects */
  if(freedObjects[i]!=nullptr)
  {
    h = freedObjects[i];
    freedObjects[i]=freedObjects[i]->prevObject;
    if(freedObjects[i]!=nullptr)
    {
      freedObjects[i]->nextObject = nullptr;
    }
  }
  else
  { 
  /*Try allocating from the heap.*/ 
    void* ptr = SourceHeap::malloc(size+sizeof(Header));
    
    if(ptr!=nullptr)
    {
  	/*If space available on Heap, allocate a block from the Heap and assign that to Header pointer.*/
  	  h = (Header *) ptr;    
    }
    else
    {
    /*If heap also exhausts, then we return nullptr*/  
      heapLock.unlock();
      return nullptr;
    }
  }

  /*update Header with relevant information*/
  h->requestedSize = sz;
  h->allocatedSize = size;

  /*Update allocated objects statistics*/
  requested += (sz);
  allocated += size;
  (size>maxAllocated)? maxAllocated=size:maxAllocated=maxAllocated; 
  ((sizeof(Header)+sz)>maxRequested)? maxRequested=size: maxRequested=maxRequested;

  /*add the object to allocated list of objects*/
  h->prevObject = allocatedObjects;
  
  if(allocatedObjects!=nullptr)
  	allocatedObjects->nextObject = h;
  allocatedObjects = h;
  h->nextObject = nullptr;

  /*returning the point after header wehre useful data can be stored*/
  heapLock.unlock();
  return (h+1); 


}
  
template <class SourceHeap>
void StatsAlloc<SourceHeap>::free(void * ptr) {

  heapLock.lock();

  if (ptr == NULL)
  {
    heapLock.unlock();
    return;
  }
  
  Header *h;
  h = (Header *)ptr-1;

  int i = getSizeClass(h->allocatedSize);

  if(h->prevObject!=nullptr)
  	(h->prevObject)->nextObject = h->nextObject;

  if(h->nextObject!=nullptr)
  	(h->nextObject)->prevObject = h->prevObject;
 
  if(freedObjects[i]!=nullptr)
  	freedObjects[i]->nextObject = h;

  if(h==allocatedObjects)
    allocatedObjects=h->prevObject;
  
  h->prevObject = freedObjects[i];
  freedObjects[i] = h;
  h->nextObject = nullptr; 

  allocated -= (h->allocatedSize);

  heapLock.unlock();
  
}

template <class SourceHeap>
size_t StatsAlloc<SourceHeap>::getSize(void * p) {
  Header *h = (Header *)p-1;
  size_t size = getSizeFromClass(getSizeClass(h->allocatedSize));
  return size; 
}

// number of bytes currently allocated  
template <class SourceHeap>
size_t StatsAlloc<SourceHeap>::bytesAllocated() {
  return allocated; 
}

// max number of bytes allocated  
template <class SourceHeap>
size_t StatsAlloc<SourceHeap>::maxBytesAllocated() {
  return maxAllocated; 
}

// number of bytes *requested* (e.g., malloc(4) might result in an allocation of 8; 4 = bytes requested, 8 = bytes allocated)
template <class SourceHeap>
size_t StatsAlloc<SourceHeap>::bytesRequested() {
  return requested; 
}
  
// max number of bytes *requested*
template <class SourceHeap>
size_t StatsAlloc<SourceHeap>::maxBytesRequested() {
  return maxRequested; 
}

template <class SourceHeap>
void StatsAlloc<SourceHeap>::walk(const std::function< void(Header *) >& f) {
  heapLock.lock();
  //printf("allocatedObjects : \n");

  Header *x;
  x=allocatedObjects;

  while(x!=nullptr)
  {
  f(x);
  x=x->prevObject;
  }

  Header *y;

  for(int i=0;i<Threshold / Base + 15;i++)
  {
    y=freedObjects[i];
    while(y!=nullptr)
    {
      
      f(y);
      y=y->prevObject;
    
    }

  }
  heapLock.unlock();

}

template <class SourceHeap>
size_t StatsAlloc<SourceHeap>::getSizeFromClass(int index) {

	if (index<1024)  
  {
    //heapLock.unlock();
		return (size_t)((index+1)*16); 
	}
  else if(index>1023 && index<1039)
  {
     // heapLock.unlock();
      return (size_t)(pow(2,index-1009));
  }
  
}


template <class SourceHeap>
int StatsAlloc<SourceHeap>::getSizeClass(size_t sz) {
  //heapLock.lock();
  if (sz<=16384)
  { //heapLock.unlock();
  	return (int)(ceil((float)sz/16))-1; 
  }
  else 
  {
    //heapLock.unlock();
	return (int)(ceil(log2(sz)))+1009;
  }
}
