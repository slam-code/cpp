
#include <iostream>                // std::cout
#include <atomic>                // std::atomic_flag
#include <thread>                // std::thread
#include <vector>                // std::vector
#include <sstream>                // std::stringstream

std::atomic_flag lock_stream = ATOMIC_FLAG_INIT;
std::stringstream stream;

void append_number(int x)
{
    while (lock_stream.test_and_set()) {
    }
    stream << "thread #" << x << '\n';
    lock_stream.clear();
}

int main()
{
    std::vector < std::thread > threads;
    for (int i = 1; i <= 10; ++i)
        threads.push_back(std::thread(append_number, i));
    for (auto & th:threads)
        th.join();

    std::cout << stream.str() << std::endl;;
    return 0;
}


/*
std::atomic_flag::clear() 介绍
清除 std::atomic_flag 对象的标志位，即设置 atomic_flag 的值为 false。clear 函数原型如下：
void clear (memory_order sync = memory_order_seq_cst) volatile noexcept;
void clear (memory_order sync = memory_order_seq_cst) noexcept;
清除 std::atomic_flag 标志使得下一次调用 std::atomic_flag::test_and_set 返回 false。
 * */