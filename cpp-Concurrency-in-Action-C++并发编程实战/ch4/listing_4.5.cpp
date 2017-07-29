#include <mutex>
#include <condition_variable>
#include <queue>
#include <memory>

template<typename T>
class threadsafe_queue///使用条件变量的线程安全队列(完整版)
{
private:
    mutable std::mutex mut;
    std::queue<T> data_queue;
    std::condition_variable data_cond;
public:
    threadsafe_queue()
    {}
    threadsafe_queue(threadsafe_queue const& other)///传入拷贝构造函数的other形参是一个const引用
    {
        std::lock_guard<std::mutex> lk(other.mut);///必须上锁，以保证other的线程安全。
        data_queue=other.data_queue;
    }

    void push(T new_value)
    {
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(new_value);
        data_cond.notify_one();
    }
/*当新的数据准备完成,调用notify_one()将会触发一个(其他线程)正在执行wait()的线程,去检查条件和wait()函数的返回状态*/

/*通过条件变量调用notify_all()成员函数,就是全部线程在都去执行wait()(检查他们等待的条件是否满足)*/
    void wait_and_pop(T& value)
    {
        std::unique_lock<std::mutex> lk(mut);//必须是unique_lock等可解锁的RAII。
        data_cond.wait(lk,[this]{return !data_queue.empty();});
        value=data_queue.front();
        data_queue.pop();
    }

    std::shared_ptr<T> wait_and_pop()
    {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk,[this]{return !data_queue.empty();});
        std::shared_ptr<T> res(std::make_shared<T>(data_queue.front()));
        data_queue.pop();
        return res;
    }

    bool try_pop(T& value)
    {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty())
            return false;
        value=data_queue.front();
        data_queue.pop();
    }

    std::shared_ptr<T> try_pop()
    {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty())
            return std::shared_ptr<T>();
        std::shared_ptr<T> res(std::make_shared<T>(data_queue.front()));
        data_queue.pop();
        return res;
    }

    bool empty() const///empty()是一个const成员函数
    {
        std::lock_guard<std::mutex> lk(mut);
        return data_queue.empty();
    }
};

int main()
{}
