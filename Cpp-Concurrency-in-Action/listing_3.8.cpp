#include <mutex>
#include <stdexcept>
#include <climits>

class hierarchical_mutex//	简单的层级互斥量实现
{
    std::mutex internal_mutex;
    unsigned long const hierarchy_value;
    unsigned long previous_hierarchy_value;
    static thread_local unsigned long this_thread_hierarchy_value;

    void check_for_hierarchy_violation()
    {
        if(this_thread_hierarchy_value <= hierarchy_value)
        {
            throw std::logic_error("mutex hierarchy violated");
        }
    }
    void update_hierarchy_value()
    {
        previous_hierarchy_value=this_thread_hierarchy_value;
        this_thread_hierarchy_value=hierarchy_value;
    }
public:
    explicit hierarchical_mutex(unsigned long value):
        hierarchy_value(value),
        previous_hierarchy_value(0)
    {}
    void lock()
    {
        check_for_hierarchy_violation();
        internal_mutex.lock();
        update_hierarchy_value();
    }
    void unlock()
    {
        this_thread_hierarchy_value=previous_hierarchy_value;
        internal_mutex.unlock();
    }
    bool try_lock()
    {
        check_for_hierarchy_violation();
        if(!internal_mutex.try_lock()) ///不能加锁则返回0
            return false;
        update_hierarchy_value();
        return true;
    }
};

thread_local unsigned long  //thread_local即每个线程中都有其拷贝的副本
    hierarchical_mutex::this_thread_hierarchy_value(ULONG_MAX);       

int main()
{
    hierarchical_mutex m1(42);
    hierarchical_mutex m2(2000);
    printf("ok 3.8 \n");


}
/*
重点是使用了thread_local的值来代表当前线程的层级值:
this_thread_hierarchy_value。它被初始化为最大值,所以最初所有线程都能被锁住。因
为其声明中有thread_local,所以每个线程都有其拷贝副本,这样线程中变量状态完全独立,
当从另一个线程进行读取时,变量的状态也完全独立。*/