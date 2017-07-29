#include <thread>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>

template<typename Iterator, typename T>
struct accumulate_block
{
    void operator()(Iterator first, Iterator last, T &result)
    {
        result = std::accumulate(first, last, result);
    }
};

template<typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init)
{
    unsigned long const length = std::distance(first, last);

    if (!length)
        return init;

    unsigned long const min_per_thread = 25;
    unsigned long const max_threads =
            (length + min_per_thread - 1) / min_per_thread;

    unsigned long const hardware_threads =
            std::thread::hardware_concurrency();

    unsigned long const num_threads =//最终的线程数
            std::min(hardware_threads != 0 ? hardware_threads : 2, max_threads);
    //hardware_threads:2即当hardware_concurrency()返回0时选择2.

    unsigned long const block_size = length / num_threads;

    std::vector<T> results(num_threads);
    std::vector<std::thread> threads(num_threads - 1);

    Iterator block_start = first;
    for (unsigned long i = 0; i < (num_threads - 1); ++i)
    {
        Iterator block_end = block_start;
        std::advance(block_end, block_size);
        threads[i] = std::thread(  //thread[i]即为求block_start-block_end之间的和。
                accumulate_block<Iterator, T>(),
                block_start, block_end, std::ref(results[i]));
        block_start = block_end;
    }
    accumulate_block<Iterator, T>()(block_start, last, results[num_threads - 1]);

    std::for_each(threads.begin(), threads.end(),
                  std::mem_fn(&std::thread::join));

    return std::accumulate(results.begin(), results.end(), init);
}

int main()
{
    std::vector<int> vi;
    for (int i = 0; i < 10; ++i)
    {
        vi.push_back(10);
    }
    int sum = parallel_accumulate(vi.begin(), vi.end(), 5);
    std::cout << "sum=" << sum << std::endl;
}
/*	std::thread::hardware_concurrency()函数将返回能同时并发在一个程序中的线程数量。
 * 例如,多核系统中,返回值可以是CPU核芯的数量。*/