#include "memo.h"
#include <cstring>
#include "time.h"


namespace  Memo
{

    std::unordered_map<std::string, Header*> Table;

    void update_Expiration_Timestamp(Header* h, int32_t expiration_time)
    {
        if (expiration_time >  SecondsIn30Days) {
            h->expiration_timestamp = expiration_time;
        }
        else {
            h->expiration_timestamp = time(NULL) + expiration_time;
        }
    }

    Header* get(std::string key)
    {
        std::unordered_map<std::string,Header*>::const_iterator got = Table.find (key);
        if ( got != Table.end() )
        {
            if (got->second->expiration_timestamp > time(NULL)) {
                return got->second;
            }
        }
        return nullptr;
    }

    Header* gets(std::string key)
    {
        std::unordered_map<std::string,Header*>::const_iterator got = Table.find (key);
        if ( got != Table.end() )
        {
            if (got->second->expiration_timestamp > time(NULL)) {
                return got->second;
            }
        }
        return nullptr;
    }

    RESPONSE set(std::string key, uint16_t flags, int32_t expiration_time, size_t size, std::string value, bool cas=false)
    {
        //printf("called %s\n",__FUNCTION__);
        Header* h;
        printf("called %s\n",__FUNCTION__);

        h=get(key);
        if (h == nullptr) {
            return(add(key, flags, expiration_time, size, value));
        }
        else {
            return(replace(key, flags, expiration_time, size, value, cas));
        }

        
    }

    RESPONSE add(std::string key, uint16_t flags, int32_t expiration_time, size_t size, std::string value)
    {
        Header* h;
        char* temp;
        printf("called %s\n",__FUNCTION__);

        h=get(key);

        if(h==nullptr)//if value not present in hash table already, allocate memory and update header. 
        {
            //add header information 
            h = (Header*) getHeap().malloc(size);
            h->flags = flags;
            update_Expiration_Timestamp(h, expiration_time);
            h->data_size = size;
            temp = (char*) (h+1);
            std::strncpy(temp,value.c_str(),size);

            printf("adding %s\n",key.c_str());

            Table.insert({key,h});
            return STORED;
        }
        //need to add key, address to hash table. use temp.  
        //
        
    }

    RESPONSE replace(std::string key, uint16_t flags, int32_t expiration_time, size_t size, std::string value, bool cas=false)
    {
        Header* h;
        char* temp;
        printf("called %s\n",__FUNCTION__);

        h=get(key);
        //printf("%p",h);


        if(h!=nullptr)
        {
            if(size==h->data_size)
            {   
                h->flags = flags;
                update_Expiration_Timestamp(h, expiration_time);
                h->data_size = size;

                temp = (char*) (h+1);
                printf("%s",temp);
                std::strncpy(temp,value.c_str(),size);
                printf(": replaced with : %s",temp);

                return STORED;
            }
            else
            {   printf("different size");
                getHeap().free((void*)h);
                // Table.delete({key,h});
                return(add(std::string(key),flags,expiration_time,size,std::string(value)));
            }
        }
        else
        {
            return NOT_FOUND;
        }
    }

    RESPONSE append(std::string key, size_t size, std::string value) {
/*
        Header* h;
        char* temp;
        printf("called %s\n",__FUNCTION__);

        h = get(key);

        if(h==nullptr)
        {
            return NOT_FOUND;
        }
        else
        {
            
            temp = (char*) h+1;
            strcat(temp,value);

            size = h->dat_size + size;

            getHeap().free((void*)h);

            return(add(std::string(key),flags,expiration_time,size,std::string(value)))

            

        }

*/
    }

    void prepend(std::string key, size_t size, std::string value) {
        // prepend code
    }

    void mem_delete(std::string key) {
        // delete code
    }

    void incr(std::string key, std::string value) {
        // incr code
    }

    void decr(std::string key, std::string value) {
        // decr code
    }

    void stats() {
        // stats code
    }

    void flush_all(int32_t exptime) {
        // expire all objects after exptime
    }

    void version() {
        // version code
    }

}
