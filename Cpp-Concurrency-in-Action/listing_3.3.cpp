#include <deque>
#include <cstddef>
#include <stdlib.h>
#include <stdio.h>

template<typename T,typename Container=std::deque<T> >
class stack
{
public:
    explicit stack(const Container&){};
    explicit stack(Container&& = Container()){};
    template <class Alloc> explicit stack(const Alloc&){};
    template <class Alloc> stack(const Container&, const Alloc&){};
    template <class Alloc> stack(Container&&, const Alloc&){};
    template <class Alloc> stack(stack&&, const Alloc&){};

    bool empty() const{};
    size_t size() const{};
    T& top(){};
    T const& top() const{};
    void push(T const&){};
    void push(T&&){};
    void pop(){};
    void swap(stack&&){};
};

void  only_single_thread()
{
    stack<int> s;

    if(!s.empty())//1 多线程,在此不安全：对空栈调用top() 是未定义行为
    {
        int const value=s.top();//2. 1-2之间存在删空栈的情况
        s.pop();
        do_something(value);
    }
}

int main()
{

    printf("ok\n");
}
