#include <iostream>
#include <thread>

void hello()
{
    std::cout<<"Hello Concurrent World\n";
}

int main()//初始线程始于main(),而新线程始于hello()
{
    std::thread t(hello);//std::thread	t对象拥有函数hello()作为其初始函数。
    t.join();
}

//使用C++线程库启动线程,可以归结为构造 	std::thread	 对象。一旦构造完毕即启动线程。