#include <mutex>

class hierarchical_mutex//使用层次锁来避免死锁
{
public:
    explicit hierarchical_mutex(unsigned level)
    {}
    
    void lock()
    {}
    void unlock()
    {}
};


hierarchical_mutex high_level_mutex(10000);
hierarchical_mutex low_level_mutex(5000);

int do_low_level_stuff()
{
    return 42;
}


int low_level_func()
{
    std::lock_guard<hierarchical_mutex> lk(low_level_mutex);
    return do_low_level_stuff();
}

void high_level_stuff(int some_param)
{}


void high_level_func()
{
    std::lock_guard<hierarchical_mutex> lk(high_level_mutex);
    high_level_stuff(low_level_func());
}

void thread_a() //遵守规则,所以它运行的没问题
{
    high_level_func();
}

hierarchical_mutex other_mutex(100);
void do_other_stuff()
{}


void other_stuff()
{
    high_level_func();
    do_other_stuff();
}

void thread_b()//无视规则,因此在运行的时候肯定会失败。
{
    std::lock_guard<hierarchical_mutex> lk(other_mutex);
    other_stuff();
}

int main()
{
    printf("ok 3.7 \n");

}
/*虽然hierarchical_mutex不是C++标准的一部分,但是它写起来很容易;
一个简单的实现在列表3.8中展示出来。尽管它是一个用户定义类型,
但它可以用于std::lock_guard<>模板中,因为它的实现有三个成员函数
满足互斥量操作:lock(),unlock()和try_lock()。

try_lock()使用很简单:当互斥量上的锁被一个线程持有,它将返回false,而不是等待调用的线程,
直到能够获取互斥量上的锁为止。在std::lock()的内部实现中,try_lock()会作为避免死锁算法的一部分。*/