
#include <bits/time.h>
#include <cstdio>
#include <sys/time.h>
#include "heap_timer.h"

void timer_handler()
{
    heap.tick();
    //setalarm();
}

/* tselect - select with timers */
int tepoll_wait( int epollfd, epoll_event *events, int max_event_number )
{
	struct timeval now;
	struct timeval tv;
	struct timeval *tvp;
	//tevent_t *tp;
	int n;

	for ( ;; )
	{
		if ( gettimeofday( &now, NULL ) < 0 )
            perror("gettimeofday");
		struct timeval time_top;
		if ( heap.top(time_top) )
		{
			tv.tv_sec = time_top.tv_sec - now.tv_sec;;
			tv.tv_usec = time_top.tv_usec - now.tv_usec;
			if ( tv.tv_usec < 0 )
			{
				tv.tv_usec += 1000000;
				tv.tv_sec--;
			}
			tvp = &tv;
		}
		else
			tvp = NULL;

		if(tvp == NULL)
			n = epoll_wait( epollfd, events, max_event_number, -1 );
		else
			n = epoll_wait( epollfd, events, max_event_number, tvp->tv_sec*1000 + tvp->tv_usec/1000 );
		if ( n < 0 )
			return -1;
		if ( n > 0 )
			return n;

        timer_handler();
	}
}

