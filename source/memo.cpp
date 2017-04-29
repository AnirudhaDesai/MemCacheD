#include "memo.h"
#include <cstring>


namespace  Memo
{

    std::unordered_map<std::string, Header*> Table;

    Header* get(std::string key)
    {
        std::unordered_map<std::string,Header*>::const_iterator got = Table.find (key);
        if ( got == Table.end() )
        {
            std::cout << "not found" << std::endl;
            return nullptr;
        }
        else
        {
            //std::cout << got->first << " is " << got->second->flags << std::endl;
            return got->second;
        }
    }

    Header* gets(std::string key)
    {
        std::unordered_map<std::string,Header*>::const_iterator got = Table.find (key);
        if ( got == Table.end() )
        {
            std::cout << "not found" << std::endl;
            return nullptr;
        }
        else
        {
            //std::cout << got->first << " is " << got->second->flags << std::endl;
            return got->second;
        }
    }

    void set(std::string key, uint16_t flags, int32_t expiration_time, size_t size, std::string value, bool cas)
    {
        printf("called %s\n",__FUNCTION__);
        printf("adding %s\n",key.c_str());
        getHeap().malloc(size);
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
            h->expiration_time = expiration_time; 
            h->data_size = size;
            temp = (char*) (h+1);
            std::strncpy(temp,value.c_str(),size);

            printf("adding %s\n",key.c_str());

            Table.insert({key,h});
        }
        //need to add key, address to hash table. use temp.  
        //
        return STORED;
    }

    void replace(std::string key, uint16_t flags, int32_t expiration_time, size_t size, std::string value, bool cas)
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
                h->expiration_time = expiration_time; 
                h->data_size = size;

                temp = (char*) (h+1);
                printf("%s",temp);
                std::strncpy(temp,value.c_str(),size);
                printf(": replaced with : %s",temp);
            }
            else
            {   printf("different size");
                getHeap().free((void*)h);
                // Table.delete({key,h});
                add(std::string(key),flags,expiration_time,size,std::string(value));
            }

        }
    }

    void append(std::string key, size_t size, std::string value) {
        // append code
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
