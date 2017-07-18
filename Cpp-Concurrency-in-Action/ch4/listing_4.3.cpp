#include <memory>
template<typename T>
class threadsafe_queue//线程安全队列的接口
{
public:
    threadsafe_queue();
    threadsafe_queue(const threadsafe_queue&);
    threadsafe_queue& operator=(const threadsafe_queue&) = delete;

    void push(T new_value);
    
    bool try_pop(T& value);
    std::shared_ptr<T> try_pop();

    void wait_and_pop(T& value);
    std::shared_ptr<T> wait_and_pop();

    bool empty() const;
};

int main()
{}
