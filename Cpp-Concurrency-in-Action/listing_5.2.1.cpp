//
// Created by shen on 16-11-6.
//
#include <atomic>

int main()
{
    std::atomic<bool> b(true); //不可拷贝构造和赋值构造
    b= false; //但是可用非原子的bool类型构造它或 赋值给它

    //load()是加载操作，sote()是存储操作，exchange()是“读-改-写”操作
    bool x=b.load(std::memory_order_acquire);
    b.store(true);
    x=b.exchange(false,std::memory_order_acq_rel);

    bool expected=false;
    std::atomic<bool > c;
    /*
    “比较/交换”操作：比较原子变量的当前值和提供的预期值。
    bool compare_exchange_weak (T& expected, T val) ;
    当前值(c)与期望值相等时，修改当前值(c)为设定值(val)，返回true
    当前值(c)与期望值不等时，将期望值(expected)修改为当前值(c)，返回false。(被修改的是expected)
     */
    while (!c.compare_exchange_weak(expected,true) && !expected )//潜在的伪失败，所以使用一个循环.
        ;

}

/*
 * http://www.cnblogs.com/haippy/p/3301408.html
 * http://coolshell.cn/articles/8239.html
该函数通常会读取原子对象封装的值，如果比较为 true(即原子对象的值等于 expected)，则替换原子对象的旧值，
但整个操作是原子的，在某个线程读取和修改该原子对象时，另外的线程不能对读取和修改该原子对象。
在第(2)种情况下，内存序（Memory Order）的选择取决于比较操作结果，如果比较结果为
true(即原子对象的值等于 expected)，则选择参数 success 指定的内存序，否则选择参数 failure 所指定的内存序。
注意，该函数直接比较原子对象所封装的值与参数 expected 的物理内容，所以某些情况下，对象的比较操作在使用
operator==() 判断时相等，但 compare_exchange_weak 判断时却可能失败，因为对象底层的物理内容中可能存在位对齐
或其他逻辑表示相同但是物理表示不同的值(比如 true 和 2 或 3，它们在逻辑上都表示"真"，但在物理上两者的表示并不相同)。
与compare_exchange_strong 不同, weak 版本的 compare-and-exchange 操作允许(spuriously 地)返回 false
(即原子对象所封装的值与参数 expected 的物理内容相同，但却仍然返回 false)，不过在某些需要循环操作的算法下这是可以
接受的，并且在一些平台下 compare_exchange_weak 的性能更好 。如果 compare_exchange_weak 的判断确实发生了伪失败
(spurious failures)——即使原子对象所封装的值与参数 expected 的物理内容相同，但判断操作的结果却为 false，
compare_exchange_weak函数返回 false，并且参数 expected 的值不会改变。
对于某些不需要采用循环操作的算法而言, 通常采用compare_exchange_strong 更好
*/