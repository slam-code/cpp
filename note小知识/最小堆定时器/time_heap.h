
#include <exception>
#include <cstdio>
#include <sys/time.h>
#include "heap_timer.h"
class time_heap
{
public:
    time_heap( int cap  = 1) throw ( std::exception )
        : capacity( cap ), cur_size( 0 )
    {
        array = new heap_timer* [capacity];
        if ( ! array )
        {
            throw std::exception();
        }
        for( int i = 0; i < capacity; ++i )
        {
            array[i] = NULL;
        }
    }

    ~time_heap()
    {
        for ( int i =  0; i < cur_size; ++i )
        {
            delete array[i];
        }
        delete [] array;
    }

public:
    int get_cursize()
    {
        return cur_size;
    }

    void add_timer( heap_timer* timer ) throw ( std::exception )
    {
        if( !timer )
        {
            return;
        }
        if( cur_size >= capacity )
        {
            resize();
        }
        int hole = cur_size++;
        int parent = 0;
        for( ; hole > 0; hole=parent )
        {
            parent = (hole-1)/2;
            if ( timercmp( &(array[parent]->expire), &(timer->expire), <= ) )
            {
                break;
            }
            array[hole] = array[parent];
        }
        array[hole] = timer;
    }
    void del_timer( heap_timer* timer )
    {
        if( !timer )
        {
            return;
        }
        // lazy delelte
        timer->cb_func = NULL;
    }
    int top(struct timeval &time_top) const
    {
        if ( empty() )
        {
            return 0;
        }
        time_top = array[0]->expire;
        return 1;
    }
    void pop_timer()
    {
        if( empty() )
        {
            return;
        }
        if( array[0] )
        {
            delete array[0];
            array[0] = array[--cur_size];
            percolate_down( 0 );
        }
    }
    void tick()
    {
        heap_timer* tmp = array[0];
        struct timeval cur;
        gettimeofday( &cur, NULL );
        while( !empty() )
        {
            if( !tmp )
            {
                break;
            }
            if( timercmp( &cur, &(tmp->expire), < ) )
            {
                break;
            }
            if( array[0]->cb_func )
            {
                array[0]->cb_func( array[0]->user_data );
            }
            pop_timer();
            tmp = array[0];
        }
    }
    bool empty() const
    {
        return cur_size == 0;
    }
    heap_timer** get_heap_array()
    {
        return array;
    }

private:
    void percolate_down( int hole )
    {
        heap_timer* temp = array[hole];
        int child = 0;
        for ( ; ((hole*2+1) <= (cur_size-1)); hole=child )
        {
            child = hole*2+1;
            if ( (child < (cur_size-1)) && timercmp( &(array[child+1]->expire), &(array[child]->expire), < ) )
            {
                ++child;
            }
            if ( timercmp( &(array[child]->expire), &(temp->expire), < ) )
            {
                array[hole] = array[child];
            }
            else
            {
                break;
            }
        }
        array[hole] = temp;
    }
    void resize() throw ( std::exception )
    {
        heap_timer** temp = new heap_timer* [2*capacity];
        for( int i = 0; i < 2*capacity; ++i )
        {
            temp[i] = NULL;
        }
        if ( ! temp )
        {
            throw std::exception();
        }
        capacity = 2*capacity;
        for ( int i = 0; i < cur_size; ++i )
        {
            temp[i] = array[i];
        }
        delete [] array;
        array = temp;
    }


private:
    heap_timer** array;
    int capacity;
    int cur_size;
};
