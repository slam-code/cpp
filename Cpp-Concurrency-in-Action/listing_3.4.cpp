#include <exception>
#include <memory>

struct empty_stack: std::exception
{
    const char* what() const throw();
};

///清单3.4中是一个接口没有条件竞争的堆栈类定义
template<typename T>
class threadsafe_stack ///接口没有条件竞争的线程安全版本的stack的定义
{
public:
    threadsafe_stack();
    threadsafe_stack(const threadsafe_stack&);
    threadsafe_stack& operator=(const threadsafe_stack&) = delete;

    void push(T new_value);
//返回指向弹出值的指针.对象分配在堆上。
//shared_ptr不仅能避免内存泄露 (因为当对象中指针销毁时,对象也会被销毁),而且标准库能够完全控制内存分配方案,
// 也就 不需要new和delete操作。
    std::shared_ptr<T> pop();///返回指向弹出值的指针.

    void pop(T& value);///将变量的引用作为参数
    bool empty() const;
};

int main()
{
    printf("ok3.4\n");
}
