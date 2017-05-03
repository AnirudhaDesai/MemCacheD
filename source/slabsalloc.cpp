#include "slabsalloc.h"

void * SlabsAlloc::store(size_t sz) {

    Header *h;

    if(sz<=0)
        return nullptr;

    //printf("called %s\n",__FUNCTION__);


    /*size will contain the closest base 16 size that needs to be alocated.*/
    int i = getSizeClass(sz);
    size_t size = getSizeFromClass(i);  

    //heapLock.lock();
    std::lock_guard<std::recursive_mutex> lock(heapLock);

    /* If this malloc will push the memory usage over the limit,
     * perform an eviction before storing
     */
    if(sz+allocated >= MAX_ALLOC || AllocatedCount[i]>=CLASS_LIM )
    {
        // use appropriate cache replacement algorithm
        
        // if LRU, evict from tail
        if (algorithm == LRU)
        {


        }

        // else if RANDOM, evict from random location
        else if(algorithm == RANDOM)
        {

        }
        // else if ______, do something else
        else if(algorithm == LANDLORD)
        {

        }
        else
        {
            // error out 
            ;
        }
    }

    /* Check in freedObjects */
    if(freedObjects[i]!=nullptr)
    {
        h = freedObjects[i];
        freedObjects[i]=freedObjects[i]->prev;
        if(freedObjects[i]!=nullptr)
        {
            freedObjects[i]->next = nullptr;
        }

        h->prev = tail_AllocatedObjects[i];
        h->next = nullptr;
        tail_AllocatedObjects[i]=h;

        AllocatedCount[i]++;

        //heapLock.unlock();
        return h;
    }
    else if(head_AllocatedObjects[i] == nullptr )
    {
        size_t size_to_malloc = size+sizeof(Header);
        void* ptr = malloc(size_to_malloc);

        if(ptr!=nullptr)
        {
            h = (Header *) ptr;  
            allocated+=size_to_malloc;
        }
        else
        {
            //heapLock.unlock();
            return nullptr;
        }

        head_AllocatedObjects[i] = h;
        tail_AllocatedObjects[i] = head_AllocatedObjects[i];

        h->prev = nullptr;
        h->next = nullptr;

        AllocatedCount[i]++;

        return tail_AllocatedObjects[i];

    }
    else
    {
        size_t size_to_malloc = size+sizeof(Header);
        void* ptr = malloc(size_to_malloc);

        if(ptr!=nullptr)
        {
            h = (Header *) ptr;  
            allocated+=size_to_malloc;
        }
        else
        {
            //heapLock.unlock();
            return nullptr;
        }

        tail_AllocatedObjects[i]->next = h;
        h->prev = tail_AllocatedObjects[i];

        tail_AllocatedObjects[i]=h;

        AllocatedCount[i]++;

        return tail_AllocatedObjects[i];
    }

    /*
       else
       { 
    /*Try allocating from the heap.*/ 
    /* void* ptr = SourceHeap::malloc(size+sizeof(Header));

       if(ptr!=nullptr)
       {
    /*If space available on Heap, allocate a block from the Heap and assign that to Header pointer.*/
    /**  h = (Header *) ptr;    
      }
      else
      {
    /*If heap also exhausts, then we return nullptr*/  
    /*  heapLock.unlock();
        return nullptr;
        }
        }

    /*update Header with relevant information*/
    //h->requestedSize = sz;
    //h->allocatedSize = size;

    /*Update allocated objects statistics*/
    /*requested += (sz);
      allocated += size;
      (size>maxAllocated)? maxAllocated=size:maxAllocated=maxAllocated; 
      ((sizeof(Header)+sz)>maxRequested)? maxRequested=size: maxRequested=maxRequested;

    /*add the object to allocated list of objects*/
    /*h->prevObject = allocatedObjects;

      if(allocatedObjects!=nullptr)
      allocatedObjects->nextObject = h;
      allocatedObjects = h;
      h->nextObject = nullptr;

    /*returning the point after header wehre useful data can be stored*/
    //heapLock.unlock();
    //return (h+1); 


}


void SlabsAlloc::remove(void * ptr) {

    //heapLock.lock();
    std::lock_guard<std::recursive_mutex> lock(heapLock);

    if (ptr == NULL)
    {
        //heapLock.unlock();
        return;
    }

    Header *h;
    h = (Header *)ptr;

    int i = getSizeClass(h->data_size);
    size_t size = getSizeFromClass(i);  
    allocated -= size;

    if(h->prev!=nullptr)
        (h->prev)->next = h->next;

    if(h->next!=nullptr)
        (h->next)->prev = h->prev;

    if(freedObjects[i]!=nullptr)
        freedObjects[i]->next = h;

    if(h==tail_AllocatedObjects[i])
        tail_AllocatedObjects[i]=h->prev;

    h->prev = freedObjects[i];
    freedObjects[i] = h;
    h->next= nullptr; 

    AllocatedCount[i]--;

    //allocated -= (h->allocatedSize);

    //heapLock.unlock();
}

/*
   template <class SourceHeap>
   size_t SlabsAlloc<SourceHeap>::getSize(void * p) {
   Header *h = (Header *)p-1;
   size_t size = getSizeFromClass(getSizeClass(h->allocatedSize));
   return size; 
   }*/

// number of bytes currently allocated  
size_t SlabsAlloc::bytesAllocated() {
    return allocated; 
}

// max number of bytes allocated  
size_t SlabsAlloc::maxBytesAllocated() {
    return maxAllocated; 
}

// number of bytes *requested* (e.g., malloc(4) might result in an allocation of 8; 4 = bytes requested, 8 = bytes allocated)
size_t SlabsAlloc::bytesRequested() {
    return requested; 
}

// max number of bytes *requested*
size_t SlabsAlloc::maxBytesRequested() {
    return maxRequested; 
}

/*
   template <class SourceHeap>
   void SlabsAlloc<SourceHeap>::walk(const std::function< void(Header *) >& f) {
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

}*/

size_t SlabsAlloc::getSizeFromClass(int index) {

    return (size_t)(pow(2,index+3));

}


int SlabsAlloc::getSizeClass(size_t sz) {

    return (int)(ceil(log2(sz)))-3;

}
