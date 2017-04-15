#include <iostream>
#include <mutex>
#include <memory>
///Double-Checked Locking的缺点:
//http://blog.csdn.net/bdss58/article/details/44813597
//http://www.aristeia.com/Papers/DDJ_Jul_Aug_2004_revised.pdf

struct some_resource
{
    void do_something()
    {}
    
};


std::shared_ptr<some_resource> resource_ptr;//延后初始化
std::mutex resource_mutex;
void foo()
{
    std::unique_lock<std::mutex> lk(resource_mutex);//线程安全的，保护共享数据的初始化
    if(!resource_ptr)
    {
        resource_ptr.reset(new some_resource);
    }
    lk.unlock();
    resource_ptr->do_something();
    /*http://blog.csdn.net/cncnlg/article/details/46635095
这个版本有什么问题呢？成本太高，每个调用都去获取锁，单例创建好之后，其实已经没有必要获取锁了，
并发情况下会导致其他线程因等待锁而被系统休眠，成本太高了。 那么，每次调用都加锁， 在获取锁之前再加一个if(m_Instance == nullptr)判断， 是否可行？
想法很好，但是有严重的缺陷，来看看 m_Instance = new Singleton, 这个new操作是先分配一块空间，然后执行构造函数，相当于：
pInstance = operator new(sizeof(Singleton)); // Step 1
new (pInstance) Singleton; // Step 2
如果一个线程执行到step 1时， 另一个线程发现 m_Instance != nullptr, 直接把 m_Instance 返回，而Step 2 还没来得及执行，返回的指针指向一块并没有构造好的空间…

     * */
}

/*
 * 为了执行这句代码，机器需要做三样事儿：
1.singleton对象分配空间。

2.在分配的空间中构造对象

3.使_instance指向分配的空间

遗憾的是编译器并不是严格按照上面的顺序来执行的。可以交换2和3.
 * */
int main()
{
    std::cout<<" 3.11 ok ";

    foo();
}
