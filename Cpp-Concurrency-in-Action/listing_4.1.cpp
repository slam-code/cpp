#include <mutex>
#include <condition_variable>
#include <thread>
#include <queue>
#include <iostream>

bool more_data_to_prepare()
{
    return false;
}

struct data_chunk
{};

data_chunk prepare_data()
{
    return data_chunk();
}

void process(data_chunk&)
{}

bool is_last_chunk(data_chunk&)
{
    return true;
}

std::mutex mut;
std::queue<data_chunk> data_queue;//在2个线程之间传递数据的队列
std::condition_variable data_cond;

void data_preparation_thread()
{
    while(more_data_to_prepare())
    {
        data_chunk const data=prepare_data();
        std::lock_guard<std::mutex> lk(mut);//上锁，再入队列
        data_queue.push(data);
        data_cond.notify_one();
    }
}

void data_processing_thread()
{
//wait会在等待条件为true时返回。如果条件不为true，wait()将解锁互斥量，并将process线程置于阻塞或者等待状态。
//当preparation线程用notify_one()通知条件变量时，process线程从睡眠中苏醒，重新获取互斥锁，并再次对条件进行检查
//在条件为true的情况下，从wait()返回，并继续持有锁。当条件不满足时，对互斥量解锁，并重新开始等待。
    while(true)
    {
        std::unique_lock<std::mutex> lk(mut);
//只能unique_lock原因：等待中的线程必须在等待期间解锁互斥量，并在之后对互斥量再次上锁。  lock_guard做不到。
//若采用lock_guard:互斥量在线程休眠期间保持【锁住状态】，准备数据的线程将无法对互斥量上锁，也无法添加数据到队列。如此，等待线程的条件便永远无法满足
        data_cond.wait(lk,[]{return !data_queue.empty();});
//wait()展开便是：1.解锁互斥量mutex, 2.堵塞当前线程，知道另一线程对条件变量发出信号, 3.重新锁住mutex.
        data_chunk data=data_queue.front();
        data_queue.pop();
        lk.unlock();
        process(data);
        if(is_last_chunk(data))
            break;
    }
}

int main()
{
    std::thread t1(data_preparation_thread);
    std::thread t2(data_processing_thread);
    
    t1.join();
    t2.join();
    std::cout<<"4.1 ok";
}
