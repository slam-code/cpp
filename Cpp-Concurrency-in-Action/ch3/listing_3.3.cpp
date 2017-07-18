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
/*以上stack的接口仍存在条件竞争。这个问题不仅存在于基于互斥量实现的接口中,
 * 在无锁实现的接口中,条件竞争依旧会产生。这是接口的问题,与其实现方式无关:

虽然empty()和size()即使在被调用时返回正确结果,但其结果是不可靠的;当它们返回
后,其他线程就可以自由地访问栈,并且可能push()多个新元素到栈中,也可能pop()一些已
在栈中的元素。这样的话,之前从empty()和size()得到的结果就有问题了。*/