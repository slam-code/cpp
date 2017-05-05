#include <thread>
#include <utility>

class scoped_thread//为了确保线程程序退出前完成.
{
    std::thread t;
public:
    explicit scoped_thread(std::thread t_)://1
        t(std::move(t_))///thread的拷贝赋值是delete的，但move不是。
    {
        if(!t.joinable()) //2
            throw std::logic_error("No thread");
    }
    ~scoped_thread()
    {
        t.join();//3
    }
    scoped_thread(scoped_thread const&)=delete;
    scoped_thread& operator=(scoped_thread const&)=delete;
};

void do_something(int& i)
{
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
    scoped_thread t(std::thread(func(some_local_state)));
        
    do_something_in_current_thread();
}

int main()
{
    f();
}
/*当主线程到达f()函数的末尾时,scoped_thread对象将会销毁,然后加入3(join)到的构造函
数1创建的线程对象中去。而在清单2.3中的thread_guard类,就要在析构的时候检查线程是
否"可加入"。这里把检查放在了构造函数中2,并且当线程不可加入时,抛出异常。*/