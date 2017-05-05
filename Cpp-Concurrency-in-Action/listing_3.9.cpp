#include <mutex>
#include <stdio.h>

using namespace std;

class some_big_object
{};

void swap(some_big_object& lhs,some_big_object& rhs)
{}

class X
{
private:
    some_big_object some_detail;
    mutable std::mutex m;
public:
    X(some_big_object const& sd):some_detail(sd){}

    friend void swap(X& lhs, X& rhs)
    {
        if(&lhs==&rhs)
            return;
        ///std::lock_guard、std::unique_lock和std::shared_lock类模板在构造时是否加锁是可选的，C++11提供了3种加锁策略。
        ///unique_lock是write lock。被锁后不允许其他线程执行被shared_lock或unique_lock的代码。
        /// 在写操作时，一般用这个，可以同时限制unique_lock的写和share_lock的读。
        std::unique_lock<std::mutex> lock_a(lhs.m,std::defer_lock);
        //	std::defer_lock_t	不请求加锁.因此lock_a可被unique_lock的lock()，
        // try_lock，unlock()函数获取,或者传递给 std::lock()
        std::unique_lock<std::mutex> lock_b(rhs.m,std::defer_lock);
        std::lock(lock_a,lock_b);
        swap(lhs.some_detail,rhs.some_detail);
    }
};

void do_something(){};

void prepare_data(){};
//函数get_lock()锁住了互斥量,然后准备数据,返回锁lk:
std::unique_lock<std::mutex> get_lock()
{
    extern std::mutex some_mutex;//声明而非实现,临时局部变量
    std::unique_lock<std::mutex>lk(some_mutex);
    prepare_data();
    return  lk;//编译器调用move()函数
}

void progress_data(){
    std::unique_lock<std::mutex>lk(get_lock());//转移lk的所有权
    do_something();
};

/*
std::unique_lock的灵活性允许对象在销毁之前放弃其拥有的锁。可以使用unlock()来做这件事,如同一个互斥量:
 std::unique_lock 的成员函数(lock,unlock)提供类似于锁定和解锁互斥量的功能。
 std::unique_lock对象在销毁前释放锁的能力使得：当锁没有必要在持有的时候,可以在
特定的代码分支对其进行选择性的释放。这对于应用性能来说很重要,因为持有锁的时间增
加会导致性能下降,其他线程会等待这个锁的释放,避免超越操作。
 */
/*void get_and_process_data()
{
    extern std::mutex the_mutex;
    std::unique_lock<std::mutex> my_lock(the_mutex);
    some_big_object
}*/
int main()
{
    printf("ok3.9 \n");
}
/*
当代码已经能规避死锁, 	std::lock()	 和 	std::lack_guard	 能组成简单的锁覆盖大多数情况,
但是有时需要更多的灵活性。在这些情况,可以使用标准库提供的std::unique_lock模板。
如 	std::lock_guard	 ,这是一个参数化的互斥量模板类,并且它提供很多RAII类型锁用来管
理 	std::lock_guard	 类型,可以让代码更加灵活。
*/


/*
try_to_lock:Attempt to lock on construction by calling member try_lock
            The object manages m, and attempts to lock it (without blocking) by calling m.try_lock().

没有上锁:defer_lock:Do not lock on construction (and assume it is not already locked by thread)
           The object manages m without locking it. m shall be a mutex object that is not currently
           locked by the constructing thread
           构造unique_lock之前,mutex没有被锁住。构造之后也不锁住。在进入临界区之前user需要调用unique_lock.lock();析构时解锁。

已经上锁:adopt_lock:Adopt current lock (assume it is already locked by thread).
            The object manages m, which is a mutex object currently locked by the constructing thread
            (the object acquires ownership over the lock).
           互斥锁之前已经上锁。unique_lock对象不需要再上锁。只在unique_lock对象销毁时自动对mutex解锁。
 * */
/*
unique_lock实现
参考网址：http://llvm.org/docs/doxygen/html/UniqueLock_8h_source.html
http://en.cppreference.com/w/cpp/thread/unique_lock
 http://www.cplusplus.com/reference/mutex/unique_lock

unique_lock:(constructor) constructs a unique_lock, optionally locking the supplied mutex.
            (destructor):unlocks the associated mutex, if owned.
 * */