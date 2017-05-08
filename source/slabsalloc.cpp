#include "slabsalloc.h"

void * SlabsAlloc::store(size_t sz, Header *& evictedObject) {

    Header *h;

    if(sz<=0)
        return nullptr;

    /*size will contain the closest base 16 size that needs to be alocated.*/
    int i = getSizeClass(sz);
    size_t size = getSizeFromClass(i); 

    printf("store called with size %d",sz); 

    // acquire the lock for the size class in question
    // (assuming that malloc is thread-safe, which it should be)
    std::lock_guard<std::recursive_mutex> lock(slabLock[i]);
    
    
    /* If this malloc will push the memory usage over the limit OR exceeds the class limit,
     * perform an eviction before storing
     */
    if(sz+allocated >= MAX_ALLOC || AllocatedCount[i]>=4 )
    {
        if(head_AllocatedObjects[i] == nullptr)
        {
            TRACE_ERROR("size bucket is empty, but heap is full. I quit.");
            return nullptr;
        }
        // use appropriate cache replacement algorithm
        
        // if LRU, evict from tail
        if (algorithm == LRU)
        {
            
            printf("Entered LRU Cache Replacement\n");
            printf("Object being removed %s\n",head_AllocatedObjects[i]->key );

            Stats::Instance().evictions++;

            evictedObject = head_AllocatedObjects[i];
            //printf("\nevictedObject in slabsalloc : %p\n", evictedObject );
             
            remove((void *) head_AllocatedObjects[i]);

        }

        // else if RANDOM, evict from random location
        else if(algorithm == RANDOM)
        {
            TRACE_DEBUG("Entered RANDOM Algorithm" );
            std::uniform_int_distribution<int> dis(0, AllocatedCount[i]);
            std::mt19937 gen(rd());
            rndNum = dis(gen);
            TRACE_DEBUG("The random number generated is : ",rndNum ); 
            Header * tempObject = head_AllocatedObjects[i];
            while(rndNum!=0)
            {
                tempObject = tempObject->next;
                rndNum--;

            }
            printf("Object being removed %s\n",tempObject->key );

            Stats::Instance().evictions++;
            evictedObject = tempObject;
            remove((void *)tempObject);  

        }
        // else if LANDLORD, evict based on least credit
        
        else if(algorithm == LANDLORD)
        {

            printf("Landlord function");
            Header *temp;
            bool flag=true;

            printf("Landlord function");

            while(flag)
            {   
                
                temp = head_AllocatedObjects[i];
                uint16_t delta= temp->landlordCost;

                while((temp=temp->next)!=nullptr)
                {
                    if(temp->landlordCost < delta)
                    {
                        delta = temp->landlordCost;
                    }

                }
                temp = head_AllocatedObjects[i];
                
                do
                {
                    temp->landlordCost = temp->landlordCost - delta;
                }while((temp=temp->next)!=nullptr);
                
                temp = head_AllocatedObjects[i];

                do
                {
                    if(temp->landlordCost<=0)
                    {
                        printf("removing %s\n",temp->key);
                        remove((void*)temp);
                        flag=false;
                        break;
                    }
                }while((temp=temp->next)!=nullptr);
            }

            Stats::Instance().evictions++;

        }
        else
        {
            // error out 
            
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

        if(tail_AllocatedObjects[i] != nullptr)
            tail_AllocatedObjects[i]->next = h;
        h->prev = tail_AllocatedObjects[i];
        h->next = nullptr;
        tail_AllocatedObjects[i]=h;
        if(head_AllocatedObjects[i]==nullptr)
            head_AllocatedObjects[i] = h;
        

        AllocatedCount[i]++;
        Stats::Instance().total_items++;
        Stats::Instance().bytes = Stats::Instance().bytes + size;

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
            return nullptr;
        }

        head_AllocatedObjects[i] = h;
        tail_AllocatedObjects[i] = head_AllocatedObjects[i];

        h->prev = nullptr;
        h->next = nullptr;

        AllocatedCount[i]++;
        
        Stats::Instance().curr_items++;
        Stats::Instance().total_items++;
        Stats::Instance().bytes = Stats::Instance().bytes + size_to_malloc;

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
            return nullptr;
        }

        tail_AllocatedObjects[i]->next = h;
        h->prev = tail_AllocatedObjects[i];

        tail_AllocatedObjects[i]=h;

        AllocatedCount[i]++;
       
        Stats::Instance().curr_items++;
        Stats::Instance().total_items++;
        Stats::Instance().bytes = Stats::Instance().bytes + size_to_malloc;


        return tail_AllocatedObjects[i];
    }

}


void SlabsAlloc::remove(void * ptr) {

    if (ptr == NULL)
    {
        return;
    }

    Header *h;
    h = (Header *)ptr;

    int i = getSizeClass(h->data_size);
    size_t size = h->data_size+sizeof(Header);
    // acquire the lock for the size class in question
    // (assuming that malloc is thread-safe, which it should be)
    std::lock_guard<std::recursive_mutex> lock(slabLock[i]);

    if(h->prev!=nullptr)
        (h->prev)->next = h->next;

    if(h->next!=nullptr)
        (h->next)->prev = h->prev;

    if(freedObjects[i]!=nullptr)
        freedObjects[i]->next = h;

    if(h==tail_AllocatedObjects[i])
        tail_AllocatedObjects[i]=h->prev;

    if(h==head_AllocatedObjects[i])
        head_AllocatedObjects[i]=h->next;

    h->prev = freedObjects[i];
    freedObjects[i] = h;
    h->next= nullptr; 

    AllocatedCount[i]--;
    Stats::Instance().curr_items--;
    Stats::Instance().bytes = Stats::Instance().bytes - size;
    allocated -= size;

}

/*
   template <class SourceHeap>
   size_t SlabsAlloc<SourceHeap>::getSize(void * p) {
   Header *h = (Header *)p-1;
   size_t size = getSizeFromClass(getSizeClass(h->allocatedSize));
   return size; 
   }*/
void SlabsAlloc::cacheReplacementUpdates(Header* h)
{
    if(algorithm == LRU)
    {
        if(h!=nullptr)
        {
        updateRecentlyUsed(h);
        }
    }
    else if(algorithm == RANDOM)
    {
        ; //do nothing
    }
    else if (algorithm == LANDLORD)
    {
        //SlabsAlloc::missTable.insert{Key,time(null)};
        //modify credit of the file
        double cost = difftime(time(NULL), h->insertedTimestamp);
        h->landlordCost = (h->landlordCost + cost)/2;
        
    }
}
void SlabsAlloc::updateRecentlyUsed(Header* h)
{
    Header* temp;
    int i = getSizeClass(h->data_size);
    temp = h;

    if(tail_AllocatedObjects[i]!=temp)
    {

        if(temp->prev!=nullptr)
            (temp->prev)->next = temp->next;
        
        if(temp->next!=nullptr)
            (temp->next)->prev = temp->prev;

        if(head_AllocatedObjects[i]==temp)
            head_AllocatedObjects[i]=head_AllocatedObjects[i]->next;

        tail_AllocatedObjects[i]->next=temp;
        temp->prev = tail_AllocatedObjects[i];
        tail_AllocatedObjects[i] = temp;
        temp->next = nullptr;
    }
}


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


size_t SlabsAlloc::getSizeFromClass(int index) {

    return (size_t)(pow(2,index));

}

int SlabsAlloc::getSizeClass(size_t sz) {
    if (sz < 1) {
        return 0;
    }
    return (int)(ceil(log2(sz)));

}

Header* SlabsAlloc::getFirstObject(int i)
{
    return head_AllocatedObjects[i];
}