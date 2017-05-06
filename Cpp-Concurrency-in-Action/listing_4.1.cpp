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
/*C++标准库对条件变量有两套实现: 	std::condition_variable	 和 	std::condition_variable_any。
 * 这两个实现都包含在	<condition_variable>头文件的声明中。两者都需要与一个互斥量一起才能工作(互斥量是为了同步);
 * 前者仅限于与 	std::mutex	 一起工作,而后者可以和任何满足最低标准的互斥量一起工作,从而加上了_any的后缀。
 * 因为 	std::condition_variable_any 更加通用,这就可能从体积、性能,以及系统资源的使用方面产生额外的开销,
 * 所以 	std::condition_variable	 一般作为首选的类型,当对灵活性有硬性要求时,
 * 我们才会去考虑std::condition_variable_any	 。*/

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
        data_cond.notify_one();//通知
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
//若采用lock_guard:互斥量在线程休眠期间保持【锁住状态】，准备数据的线程将无法对互斥量上锁，也无法添加数据到队列。
// 如此，等待线程的条件便永远无法满足
        data_cond.wait(lk,[]{return !data_queue.empty();});
//data_cond.wait()展开便是：1.解锁互斥量mutex, 2.堵塞当前线程，直到另一线程对条件变量发出信号, 3.重新锁住mutex.
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
    std::thread t1(data_preparation_thread);//生产者
    std::thread t2(data_processing_thread);//消费者
    
    t1.join();
    t2.join();
    std::cout<<"4.1 ok";
}
/*线程同步:,C++标准库提供了一些工具可用于同步操作,形式上表现为条件变量(condition	variables)和期望(futures)。*/