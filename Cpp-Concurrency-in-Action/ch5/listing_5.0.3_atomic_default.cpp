//
// Created by shen on 16-11-6.
//

include <iostream>        // std::cout
#include <atomic>         // std::atomic, std::atomic_flag, ATOMIC_FLAG_INIT
#include <thread>         // std::thread, std::this_thread::yield
#include <vector>         // std::vector
// 由 false 初始化一个 std::atomic<bool> 类型的原子变量
;
std::atomic<bool> ready(false);
std::atomic_flag winner = ATOMIC_FLAG_INIT;

void do_count1m(int id)
{
    while (!ready) { std::this_thread::yield(); } // 等待 ready 变为 true.

    for (volatile int i=0; i<1000000; ++i) {} // 计数

    if (!winner.test_and_set()) {
        std::cout << "thread #" << id << " won!\n";
    }
}

int main ()
{
    std::vector<std::thread> threads;
    std::cout << "spawning 10 threads that count to 1 million...\n";
    for (int i=1; i<=10; ++i) threads.push_back(std::thread(count1m,i));
    ready = true;

    for (auto& th : threads) th.join();
    return 0;
}

/*
默认构造函数，由默认构造函数创建的 std::atomic 对象处于未初始化(uninitialized)状态，
对处于未初始化(uninitialized)状态 std::atomic对象可以由 atomic_init 函数进行初始化。
初始化构造函数，由类型 T初始化一个 std::atomic对象。
拷贝构造函数被禁用。
*/