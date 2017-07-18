//
// Created by shen on 16-11-6.
//

#include <thread>
#include <vector>
#include <iostream>
#include <atomic>

std::atomic_flag lock = ATOMIC_FLAG_INIT;

void f(int n)
{
    for (int cnt = 0; cnt < 100; ++cnt) {
        while (lock.test_and_set(std::memory_order_acquire))  // acquire lock
            ; // spin,如果没有获取则处于自旋状态
        std::cout << "Output from thread " << n << '\n';
        lock.clear(std::memory_order_release);               // release lock
    }
}

int main()
{
    std::vector<std::thread> v;
    for (int n = 0; n < 10; ++n) {
        v.emplace_back(f, n);
    }
    for (auto& t : v) {
        t.join();
    }
}

/*http://www.cnblogs.com/haippy/p/3252056.html
在上面的程序中，std::atomic_flag 对象 lock 的上锁操作可以理解为 lock.test_and_set(std::memory_order_acquire);
(此处指定了 Memory Order，更多有关 Memory Order 的概念，我会在后续的文章中介绍)，
解锁操作相当与 lock.clear(std::memory_order_release)。
在上锁的时候，如果 lock.test_and_set 返回 false，则表示上锁成功（此时 while 不会进入自旋状态），
因为此前 lock 的标志位为 false(即没有线程对 lock 进行上锁操作)，但调用 test_and_set 后 lock 的标志位为 true，
说明某一线程已经成功获得了 lock 锁。
如果在该线程解锁（即调用 lock.clear(std::memory_order_release)） 之前，另外一个线程也调用
lock.test_and_set(std::memory_order_acquire) 试图获得锁，则 test_and_set(std::memory_order_acquire) 返回 true，
则 while 进入自旋状态。如果获得锁的线程解锁（即调用了 lock.clear(std::memory_order_release)）之后，
某个线程试图调用 lock.test_and_set(std::memory_order_acquire) 并且返回 false，
则 while 不会进入自旋，此时表明该线程成功地获得了锁。
*/