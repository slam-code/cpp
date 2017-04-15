#include <thread>
#include <zconf.h>
#include <iostream>

void do_something(int& i)
{
    if(i<100000)
        printf("i=%d ,",i);

    else
        std::cout<<" error";
    ++i;
}

struct func
{
    int& i;

    func(int& i_):i(i_){}

    void operator()()
    {
        for(unsigned j=0;j<1000000;++j)
        {
            do_something(i);
        }
    }
};


void oops()
{
    int some_local_state=0;
    func my_func(some_local_state);
    std::thread my_thread(my_func);
    usleep(1);
    my_thread.detach();
}

int main()
{
    oops();
}
