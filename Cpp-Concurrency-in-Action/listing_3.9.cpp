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
        //	std::defer_lock_t	不请求加锁.因此lock_a可被unique_lock的lock()，try_lock，unlock()函数获取,或者传递给 std::lock()
        std::unique_lock<std::mutex> lock_b(rhs.m,std::defer_lock);
        std::lock(lock_a,lock_b);
        swap(lhs.some_detail,rhs.some_detail);
    }
};

void do_something(){};

void prepare_data(){};

std::unique_lock<std::mutex> get_lock()
{
    extern std::mutex some_mutex;//临时局部变量
    std::unique_lock<std::mutex>lk(some_mutex);
    prepare_data();
    return  lk;//编译器调用move()函数
}

void progress_data(){
    std::unique_lock<std::mutex>lk(get_lock());//转移lk的所有权
    do_something();
};


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
