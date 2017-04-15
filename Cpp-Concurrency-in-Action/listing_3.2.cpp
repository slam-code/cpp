#include <mutex>
#include <iostream>
using namespace std;

class some_data
{
    int a=0;
    std::string b="hello";
public:
    some_data()
    {
        cout<<"a= "<<a<<" b= "<<b<<endl;
    }
    void do_something()
    {
        a=a+1;
        b="hello again";
        cout<<"a= "<<a<<" b= "<<b<<endl;
    }
};

class data_wrapper
{
private:
    some_data data;
    std::mutex m;
public:
    template<typename Function>
    void process_data(Function func)
    {
        std::lock_guard<std::mutex> l(m);
        func(data);//根据传入的函数对 data进行处理，data传引用
    }
};
some_data* unprotected;

void malicious_function(some_data& protected_data) //传递了欲保护的数据data作为函数参数。malicious adj.	恶意的
{
    unprotected=&protected_data;//泄露了成员地址
}

void foo()
{
    data_wrapper x;
    x.process_data(malicious_function);//传入函数指针
    unprotected->do_something();
}

int main()
{
    foo();
}
