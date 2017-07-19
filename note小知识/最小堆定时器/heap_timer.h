
#include <sys/time.h>
#include <cstdio>

class heap_timer
{
public:
    heap_timer( int ms_delay )
    {
        gettimeofday( &expire, NULL );
        expire.tv_usec += ms_delay * 1000;
        if ( expire.tv_usec > 1000000 )
        {
            expire.tv_sec += expire.tv_usec / 1000000;
            expire.tv_usec %= 1000000;
        }
    }

public:
    struct timeval expire;
    void (*cb_func)( client_data* );
    client_data* user_data;
    ~heap_timer()
    {
        delete user_data;
    }
};


