#include "memo.h"
#include <cstring>
#include "time.h"
#include <stdlib.h>
#include <limits.h>
#include <exception>

SlabsAlloc* alloc;

namespace  Memo
{
    std::unordered_map<std::string, Header*> Table;

    void update_Expiration_Timestamp(Header* h, int32_t expiration_time)
    {
        if (expiration_time < 0) {
            h->expiration_timestamp = std::numeric_limits<time_t>::min();
        }
        else if (expiration_time == 0){
            h->expiration_timestamp = 0;
        }
        else if (expiration_time >  SecondsIn30Days) {
            h->expiration_timestamp = expiration_time;
        }
        else {
            h->expiration_timestamp = time(NULL) + expiration_time;
        }
    }

    bool validExpirationTime(Header* h) {
        if (h->expiration_timestamp == 0 || h->expiration_timestamp >= time(NULL)) {
            return true;
        }
        return false;
    }

    Header* get(std::string key, const char* callerFunction)
    {
        if (std::strcmp(callerFunction, "handle_get") == 0)
        {   
            // Increment stats only if get called by handle_get. Calls from other functions are internal
            Stats::Instance().cmd_get++;
            
        }

        std::unordered_map<std::string,Header*>::const_iterator got = Table.find (key);
        if ( got != Table.end() )
        {
            if (validExpirationTime(got->second)) {
                alloc->cacheReplacementUpdates((Header *) got->second);
                // it is a get hit
                if (std::strcmp(callerFunction, "handle_get") == 0) {
                    // Increment stats only if get called by handle_get. Calls from other functions are internal

                    Stats::Instance().get_hits++;
                }
                return got->second;
            }
            else
            {
                Table.erase({key});
                printf("Key expired");
                return nullptr;
            }
        }
        else
        {
            //it is a get miss.
            if (std::strcmp(callerFunction, "handle_get") == 0)
            {
                // Increment stats only if get called by handle_get. Calls from other functions are internal

                Stats::Instance().get_misses++;
            }
        }
        return nullptr;
    }

    RESPONSE set(std::string key, uint16_t flags, int32_t expiration_time, size_t size, std::string value, bool cas)
    {
        //printf("called %s\n",__FUNCTION__);
        Header* h;
        printf("called %s\n",__FUNCTION__);

        //Stats::Instance().cmd_set++;

        h=get(key, __FUNCTION__);
        if (h == nullptr) {
            return(add(key, flags, expiration_time, size, value));
        }
        else {
            return(replace(key, flags, expiration_time, size, value, cas));
        }

        
    }

    RESPONSE add(std::string key, uint16_t flags, int32_t expiration_time, size_t size, std::string value, bool updateExpirationTime)
    {
        Header* h;
        Header *evictedObject;
        evictedObject = NULL;
        char* temp;
        printf("called %s\n",__FUNCTION__);

        Stats::Instance().cmd_set++;

        h=get(key, __FUNCTION__);

        if(h==nullptr)//if value not present in hash table already, allocate memory and update header. 
        {
            //add header information
            h = (Header*) alloc->store(size, evictedObject);
            printf("\n evictedObject : %s\n", evictedObject->key );
            if(evictedObject!=NULL)
            {
                Table.erase({evictedObject->key});
            }
            std::strncpy(h->key, key.c_str(), 251);
            h->flags = flags;
            if (updateExpirationTime) {
                update_Expiration_Timestamp(h, expiration_time);
            }
            else {
                h->expiration_timestamp = expiration_time;
            }
            h->data_size = size;
            temp = (char*) (h+1);
            std::strncpy(temp,value.c_str(),size+1);

            printf("adding %s\n",key.c_str());

            Table.insert({key,h});
            return STORED;
        }
        //need to add key, address to hash table. use temp.  
        //
        return ERROR;
    }

    RESPONSE replace(std::string key, uint16_t flags, int32_t expiration_time, size_t size, std::string value, bool cas, bool updateExpirationTime)
    {
        Header* h;
        char* temp;
        printf("called %s\n",__FUNCTION__);

        Stats::Instance().cmd_set++;

        h=get(key, __FUNCTION__);
        //printf("%p",h);


        if(h!=nullptr)
        {
            if(alloc->getSizeClass(h->data_size)==alloc->getSizeClass(size))
            {   
                h->flags = flags;
                if (updateExpirationTime) {
                    update_Expiration_Timestamp(h, expiration_time);
                }
                else {
                    h->expiration_timestamp = expiration_time;
                }
                h->data_size = size;

                temp = (char*) (h+1);
                printf("%s",temp);
                std::strncpy(temp,value.c_str(),size+1);
                printf(": replaced with : %s",temp);

                return STORED;
            }
            else
            {   printf("different size");
                alloc->remove((void*)h);
                Table.erase({key});
                return(add(std::string(key),flags,expiration_time,size,std::string(value),updateExpirationTime));
            }
        }
        else
        {
            return NOT_FOUND;
        }
    }

    RESPONSE append(std::string key, size_t size, std::string value) {

        Header* h;
        char* temp;
        char* temp_key;
        int16_t temp_flags;
        int32_t temp_expiration_time; 

        printf("called %s\n",__FUNCTION__);

        Stats::Instance().cmd_set++;

        h = get(key,__FUNCTION__);

        if(h==nullptr)
        {
            return NOT_FOUND;
        }
        else if(alloc->getSizeClass(h->data_size)==alloc->getSizeClass(h->data_size + size))
        {
            temp = (char*) (h+1);
            std::strncat(temp,value.c_str(), size+1);
            h->data_size = h->data_size + size;
            return STORED;
        }
        else
        {    
            temp = (char*) (h+1);
            std::strncat(temp, value.c_str(), size+1);
            size = h->data_size + size;
            temp_flags = h->flags;
            temp_expiration_time = h->expiration_time;

            alloc->remove((void*)h);
            Table.erase({key});


            return(add(key,temp_flags,temp_expiration_time,size,std::string(temp)));

          
        }


    }

    RESPONSE prepend(std::string key, size_t size, std::string value) {
        Header* h;
        char* data;
        int16_t temp_flags;
        int32_t temp_expiration_time;

        printf("called %s\n",__FUNCTION__);

        Stats::Instance().cmd_set++;

        h = get(key,__FUNCTION__);

        if(h==nullptr)
        {
            return NOT_FOUND;
        }
        else if(alloc->getSizeClass(h->data_size)==alloc->getSizeClass(h->data_size + size))
        {

            printf("same size class\n");
            data = (char*) (h+1);
            std::string temp = value + std::string(data);
            std::strncpy(data, temp.c_str(), std::strlen(temp.c_str())+1);
            h->data_size = h->data_size + size;
            return STORED;
        }
        else
        {


            printf("different size class\n");
            data = (char*) (h+1);

            std::string temp = value + std::string(data);
            size = h->data_size + size;
            temp_flags = h->flags;
            temp_expiration_time = h->expiration_time;

            alloc->remove((void*)h);
            Table.erase({key});

            return(add(key,temp_flags,temp_expiration_time,size,temp));

        }

    }

    RESPONSE mem_delete(std::string key) {
        // delete code
        Header* h;
        printf("called %s\n",__FUNCTION__);

        h = get(key,__FUNCTION__);

        if(h!=nullptr)
        {
            alloc->remove((void*)h);
            Table.erase({key});
            return DELETED;
        }
        else
        {       
            return NOT_FOUND;
        }
    }

    Header* incr(std::string key, std::string value) {
        
        Header* h;
        printf("called %s\n",__FUNCTION__);

        h = get(key,__FUNCTION__);
        char* temp;
        long unsigned int num;

        if(h==nullptr)
        {
            //incr on missing keys. update stats 
            Stats::Instance().incr_misses++;
            return nullptr;
        }
        else
        {
            //incr hit. update stats 
            Stats::Instance().incr_hits++;
            temp = (char*) (h+1);
            printf("value=%s",temp);
            try
            {
                num = strtol(temp, NULL,10);
            }
            catch(std::exception& e)
            {
                return nullptr;
            }
            num += std::strtol(value.c_str(), NULL,10);
            printf("incremented:%lu",num);

            std::string num_str = std::to_string(num);
            RESPONSE res = replace(key, h->flags, h->expiration_time, std::strlen(num_str.c_str()), num_str);
            if (res == STORED) {
                return get(key, __FUNCTION__);
            }
            return nullptr;
        }
    }

    Header* decr(std::string key, std::string value) {
        Header* h;
        printf("called %s\n",__FUNCTION__);

        h = get(key,__FUNCTION__);
        char* temp;
        long unsigned int num;

        if(h==nullptr)
        {
            // it is decr miss. update stats
            Stats::Instance().decr_misses++;
            return nullptr;
        }
        else
        {
            //decr hit. update stats
            Stats::Instance().decr_hits++;
            
            temp = (char*) (h+1);
            printf("value=%s",temp);
            try
            {
                num = std::strtol(temp, NULL,10);
            }
            catch(std::exception& e)
            {
                return nullptr;
            }
            int64_t signed_num = (int64_t )num - strtol(value.c_str(), NULL,10);
            if (signed_num < 0) {
                num = 0;
            }
            else {
                num -= strtol(value.c_str(), NULL,10);
            }
            printf("decreamented:%lu",num);

            std::string num_str = std::to_string(num);
            RESPONSE res = replace(key, h->flags, h->expiration_time, std::strlen(num_str.c_str()), num_str);
            if (res == STORED) {
                return get(key, __FUNCTION__);
            }
            return nullptr;

        }
    }

    void stats(char*& response_str, size_t* response_len) {
        // stats code
        printf("Called Stats function \n" );
        Stats::Instance().printStats(response_str,response_len);

    }

    void flush_all(int32_t exptime) {
        // expire all objects after exptime

        Header* temp;
        int i;

        for(i=0;i<23;i++)
        {
            temp = alloc->getFirstObject(i);

            if(temp!=nullptr)
            {
                if(exptime==0)
                {
                    update_Expiration_Timestamp(temp,-1);
                }
                else
                {
                    update_Expiration_Timestamp(temp,exptime);
                }

            }
        }


        Stats::Instance().cmd_flush++;

    }

    void version() {
        // version code
    }

}
