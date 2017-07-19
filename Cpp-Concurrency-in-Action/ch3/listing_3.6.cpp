#include <mutex>
#include <iostream>

using namespace std;
class some_big_object
{
public:
    some_big_object(int a)
    {
        cout<<"some_big_object()...a="<<a<<endl;
    }

};

void swap(some_big_object& lhs,some_big_object& rhs)
{
    cout<<"swap() in out ..."<<endl;
}

class X
{
private:
    some_big_object some_detail;
    mutable std::mutex m;
public:
    X(some_big_object const& sd):some_detail(sd){
        cout<<"X()..."<<endl;
    }

    friend void swap(X& lhs, X& rhs)
    {
        if(&lhs==&rhs) ///必须检查是否是同一对象。因为对同一mutex加锁多次可能导致未定义行为。
            return;
        std::lock(lhs.m,rhs.m);///一次性锁住多个互斥量mutex
        std::lock_guard<std::mutex> lock_a(lhs.m,std::adopt_lock);
        std::lock_guard<std::mutex> lock_b(rhs.m,std::adopt_lock);
        ///adopt_lock:假定当前线程已经获得互斥对象的所有权，所以不再上锁(即不执行mutex.lock(),但执行mutex.unlock())。
        cout<<"swap in X..."<<endl;
        swap(lhs.some_detail,rhs.some_detail);//不调用std::swap()函数。(即使有可能在swap中调用std::swap)
    }
};

int main()
{
    some_big_object sb1(1);
    X x1(sb1),x2(some_big_object(2));
    swap(x1,x2);

    printf("ok 3.6 \n");
}
/*需要注意的是,当使用std::lock 去锁lhs.m或rhs.m时,可能会抛出异常;这种情况下,异常会传播
到std::lock之外。
 当std::lock成功的获取一个互斥量上的锁,并且当其尝试从另一个互斥量上再获取锁时,就会有异常抛出,
 第一个锁也会随着异常的产生而自动释放,所以std::lock要么将两个锁都锁住,要不一个都不锁。*/