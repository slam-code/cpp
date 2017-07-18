#include <exception>
#include <stack>
#include <mutex>
#include <memory>

struct empty_stack: std::exception ///默认的继承访问权限:struct是public的，class是private的。
{
    const char* what() const throw()
    {
        return "empty stack";
    }
    
};

template<typename T>
class threadsafe_stack//基于3.4的一个简单实现
{
private:
    std::stack<T> data;
    mutable std::mutex m;//锁住的颗粒过大,一个全局互斥量要去保护全部共享数据。细粒度锁:使用多个互斥量则可能出现死锁。
public:
    threadsafe_stack(){}
    threadsafe_stack(const threadsafe_stack& other)
    {
        std::lock_guard<std::mutex> lock(other.m);
        data=other.data;
    }
    threadsafe_stack& operator=(const threadsafe_stack&) = delete;

    void push(T new_value)
    {
        std::lock_guard<std::mutex> lock(m);
        data.push(new_value);
    }
    std::shared_ptr<T> pop()
    {
        std::lock_guard<std::mutex> lock(m);
        if(data.empty()) throw empty_stack();

        std::shared_ptr<T> const res(std::make_shared<T>(data.top()));
        data.pop();
        return res;
    }
    void pop(T& value)
    {
        std::lock_guard<std::mutex> lock(m);
        if(data.empty()) throw empty_stack();
        value=data.top();
        data.pop();
    }
    bool empty() const//此处说明了为啥m需要 mutable.
    {
        std::lock_guard<std::mutex> lock(m);
        return data.empty();
    }
};

int main()
{
    threadsafe_stack<int> si;
    si.push(5);
    si.pop();
    if(!si.empty())
    {
        int x;
        si.pop(x);
    }
    printf("ok 3.5");
    
}
