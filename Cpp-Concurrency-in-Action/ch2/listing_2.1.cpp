#include <thread>
#include <zconf.h>
#include <iostream>

void do_something(int& i)
{
    if(i<100000)
        printf("i=%d ,",i);

    else
        std::cout<<" error";
    ++i;
}

struct func
{
    int& i;

    func(int& i_):i(i_){}

    void operator()()
    {
        for(unsigned j=0;j<1000000;++j)
        {
            do_something(i);
        }
    }
};


void oops()
{
    int some_local_state=0;//如果不等待线程,就必须保证线程结束之前,可访问的数据有效性。
    func my_func(some_local_state);
    std::thread my_thread(my_func);//线程在std::thread对象创建(为线程指定任务)时启动。
    usleep(1);
    //启动了线程,需要明确是要等待线程结束(jion),还是让其自主运行(detach)
    my_thread.detach();//必须在 	std::thread	 对象销毁之前做出决定
}

//函数已经结束,线程依旧访问局部变量
int main()
{
    oops();
}