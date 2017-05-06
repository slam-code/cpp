#include <iostream>
#include <thread>
#include <unistd.h>


std::thread::id master_thread;
void hello()
{
    std::cout<<"Hello Concurrent World,thread_id="<<std::this_thread::get_id()<<"\n";
}

void hello2(int i)
{
    std::cout<<"before main,i="<<i<<",tthread_id="<<std::this_thread::get_id()<<std::endl;
}

std::thread t0(hello2,2);
int main()//初始线程始于main(),而新线程始于hello()
{
    sleep(1);
    std::thread t (hello);//std::thread	t对象拥有函数hello()作为其初始函数。
    master_thread=std::this_thread::get_id();
    std::cout<<"main id="<<master_thread<<std::endl;
    t.join();
    t0.join();//不jion则发生异常。
}

//使用C++线程库启动线程,可以归结为构造 	std::thread	 对象。一旦构造完毕即启动线程。