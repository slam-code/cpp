#include <thread>

class thread_guard
{
    std::thread& t;
public:
    explicit thread_guard(std::thread& t_):
        t(t_)
    {}
    ~thread_guard()
    {
        if(t.joinable())
        {
            t.join();//2
        }
    }
    thread_guard(thread_guard const&)=delete;
    thread_guard& operator=(thread_guard const&)=delete;
};

void do_something(int& i)
{
    printf("i=%d,",i);
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

void do_something_in_current_thread()
{}


void f()
{
    int some_local_state;
    func my_func(some_local_state);
    std::thread t(my_func);
    thread_guard g(t);
        
    do_something_in_current_thread();
} //4

/*当线程执行到4处时,局部对象就要被逆序销毁了。因此,thread_guard对象g是第一个被销毁的,
 * 这时线程在析构函数中被加入2(join)到原始线程中。即使do_something_in_current_thread抛出一个异常,
这个销毁依旧会发生。*/

int main()
{
    f();
}
