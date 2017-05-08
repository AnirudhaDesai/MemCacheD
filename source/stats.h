#ifndef _STATS_H_
#define _STATS_H_
#include <sstream>
#include <cstring>


typedef struct r_usage    //used in stats class below 
{
    uint32_t seconds;
    uint32_t microseconds; 
};

class Stats
{

    Stats() :
        pid(0),
        uptime(0),
        version("1.0.0"),
        pointer_size(0),
        userUsage({0,0}),
        systemUsage({0,0}),
        curr_items(0),
        total_items(0),
        bytes(0),
        curr_connections(0),
        total_connections(0),
        connection_structures(0),
        reserved_fds(0),
        cmd_get(0),
        cmd_set(0),
        cmd_flush(0),
        cmd_touch(0),
        get_hits(0),
        get_misses(0),
        delete_misses(0),
        delete_hits(0),
        incr_misses(0),
        incr_hits(0),
        decr_misses(0),
        decr_hits(0),  
        cas_misses(0), 
        cas_hits(0), 
        cas_badval(0),
        touch_hits(0), 
        touch_misses(0), 
        auth_cmds(0), 
        auth_errors(0), 
        evictions(0),
        reclaimed(0),
        bytes_read(0),
        bytes_written(0),
        limit_maxbytes(0),
        threads(0), 
        conn_yields(0), 
        hash_power_level(0),
        hash_bytes(0),
        hash_is_expanding(0),
        expired_unfetched(0),
        evicted_unfetched(0) 
        {
            pid=::getpid();
        }
    public:

    static Stats& Instance()
    {
        static Stats s;
        return s;

    }

    void printStats(char*& response_str, size_t* response_len)
    {
        std::ostringstream  oss;
        std::string finalOutput;
        std::string stat = "STAT  ";

        oss<<stat<<"pid: "<<pid<<"\n";
        oss<<stat<<"uptime: "<<uptime<<"\n";
        oss<<stat<<"pointer_size: "<<pointer_size<<"\n";
        oss<<stat<<"curr_items: "<<curr_items<<"\n";
        oss<<stat<<"total_items: "<<total_items<<"\n";
        oss<<stat<<"bytes: "<<bytes<<"\n";
        oss<<stat<<"curr_connections: "<<curr_connections<<"\n";
        oss<<stat<<"total_connections: "<<total_connections<<"\n";
        oss<<stat<<"connection_structures: "<<connection_structures<<"\n";
        oss<<stat<<"reserved_fds: "<<reserved_fds<<"\n";
        oss<<stat<<"cmd_get: "<<cmd_get<<"\n";
        oss<<stat<<"cmd_set: "<<cmd_set<<"\n";
        oss<<stat<<"cmd_flush: "<<cmd_flush<<"\n";
        oss<<stat<<"cmd_touch: "<<cmd_touch<<"\n";
        oss<<stat<<"get_hits: "<<get_hits<<"\n";
        oss<<stat<<"get_misses: "<<get_misses<<"\n";
        oss<<stat<<"delete_misses: "<<delete_misses<<"\n";
        oss<<stat<<"delete_hits: "<<delete_hits<<"\n";
        oss<<stat<<"incr_misses: "<<incr_misses<<"\n";
        oss<<stat<<"incr_hits: "<<incr_hits<<"\n";
        oss<<stat<<"decr_misses: "<<decr_misses<<"\n";
        oss<<stat<<"decr_hits: "<<decr_hits<<"\n";
        oss<<stat<<"cas_misses: "<<cas_misses<<"\n";
        oss<<stat<<"cas_hits: "<<cas_hits<<"\n";
        oss<<stat<<"cas_badval: "<<cas_badval<<"\n";
        oss<<stat<<"touch_hits: "<<touch_hits<<"\n";
        oss<<stat<<"touch_misses: "<<touch_misses<<"\n";
        oss<<stat<<"auth_cmds: "<<auth_cmds<<"\n";
        oss<<stat<<"auth_errors: "<<auth_errors<<"\n";
        oss<<stat<<"evictions: "<<evictions<<"\n";
        oss<<stat<<"reclaimed: "<<reclaimed<<"\n";
        oss<<stat<<"bytes_read: "<<bytes_read<<"\n";
        oss<<stat<<"bytes_written: "<<bytes_written<<"\n";
        oss<<stat<<"limit_maxbytes: "<<limit_maxbytes<<"\n";
        oss<<stat<<"threads: "<<threads<<"\n";
        oss<<stat<<"conn_yields: "<<conn_yields<<"\n";
        oss<<stat<<"hash_power_level: "<<hash_power_level<<"\n";
        oss<<stat<<"hash_bytes: "<<hash_bytes<<"\n";
        oss<<stat<<"hash_is_expanding: "<<hash_is_expanding<<"\n";
        oss<<stat<<"cmd_flush: "<<cmd_flush<<"\n";
        oss<<stat<<"expired_unfetched: "<<expired_unfetched<<"\n";
        oss<<stat<<"evicted_unfetched: "<<evicted_unfetched<<"\n";
        finalOutput = oss.str();
        response_str = (char*)malloc(finalOutput.length());
        strcpy(response_str, finalOutput.c_str());
        *response_len = strlen(response_str);
        
    }

    pid_t pid;
    int32_t uptime;
    std::string version;
    int32_t pointer_size;
    r_usage userUsage;
    r_usage systemUsage;
    uint32_t curr_items = 0;
    uint32_t total_items;
    uint64_t bytes;
    uint32_t curr_connections;
    uint32_t total_connections;
    uint32_t connection_structures;
    uint32_t reserved_fds;
    uint64_t cmd_get;
    uint64_t cmd_set;
    uint64_t cmd_flush;
    uint64_t cmd_touch;
    uint64_t get_hits;
    uint64_t get_misses;
    uint64_t delete_misses;
    uint64_t delete_hits;
    uint64_t incr_misses;
    uint64_t incr_hits;
    uint64_t decr_misses;
    uint64_t decr_hits;  
    uint64_t cas_misses; 
    uint64_t cas_hits; 
    uint64_t cas_badval;
    uint64_t touch_hits; 
    uint64_t touch_misses; 
    uint64_t auth_cmds; 
    uint64_t auth_errors; 
    uint64_t evictions;
    uint64_t reclaimed;
    uint64_t bytes_read;
    uint64_t bytes_written;
    uint32_t limit_maxbytes;
    uint32_t threads; 
    uint64_t conn_yields; 
    uint32_t hash_power_level;
    uint64_t hash_bytes;
    bool hash_is_expanding = false;
    uint64_t expired_unfetched;
    uint64_t evicted_unfetched; 

};


#endif // _STATS_H_
