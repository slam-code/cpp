// atomic_flag as a spinning lock
#include <iostream>       // std::cout
#include <atomic>         // std::atomic_flag
#include <thread>         // std::thread
#include <vector>         // std::vector
#include <sstream>        // std::stringstream

/*
 bool test_and_set (memory_order sync = memory_order_seq_cst) noexcept;

 Sets the atomic_flag and returns whether it was already set immediately before the call.

 The entire operation is atomic (an atomic read-modify-write operation):
 the value is not affected by other threads between the instant its value
 is read (to be returned) and the moment it is modified by this function.

 true if the flag was set before the call.
 false otherwise.
*/

std::atomic_flag lock_stream = ATOMIC_FLAG_INIT;
std::stringstream stream;

void append_number(int x) {
    while (lock_stream.test_and_set()) {}
    stream << "thread #" << x << '\n';
    lock_stream.clear();
}

int main ()
{
    std::vector<std::thread> threads;
    for (int i=1; i<=10; ++i) threads.push_back(std::thread(append_number,i));
    for (auto& th : threads) th.join();

    std::cout << stream.str();
    return 0;
}