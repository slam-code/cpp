
#include <iostream>              // std::cout
#include <atomic>                // std::atomic, std::atomic_flag, ATOMIC_FLAG_INIT
#include <thread>                // std::thread, std::this_thread::yield
#include <vector>                // std::vector

std::atomic<bool> ready(false);    // can be checked without being set
std::atomic_flag winner = ATOMIC_FLAG_INIT;    // always set when checked

void count1m(int id)
{
    while (!ready) {
        std::this_thread::yield();
    } // 等待主线程中设置 ready 为 true.

    for (int i = 0; i < 1000000; ++i) {
    } // 计数.

    // 如果某个线程率先执行完上面的计数过程，则输出自己的 ID.
    // 此后其他线程执行 test_and_set 是 if 语句判断为 false，
    // 因此不会输出自身 ID.
    if (!winner.test_and_set()) {//之前未被设置，返回true。
        std::cout << "thread #" << id << " won!\n";
    }
};

/*
test_and_set() 函数检查 std::atomic_flag 标志
(一):
    1),如果 std::atomic_flag 之前没有被设置过，
    2),则设置 std::atomic_flag 的标志，并返回先前该 std::atomic_flag 对象是否被设置过.

(二):
    1),如果之前std::atomic_flag 对象已被设置，则返回 true
    2),否则返回 false。

test-and-set 操作是原子的（因此 test-and-set 是原子 read-modify-write （RMW）操作）
*/

int main()
{
    std::vector<std::thread> threads;
    std::cout << "spawning 10 threads that count to 1 million...\n";
    for (int i = 1; i <= 10; ++i)
        threads.push_back(std::thread(count1m, i));
    ready = true;

    for (auto & th:threads)
        th.join();

    return 0;
}