#include <list>
#include <mutex>
#include <algorithm>

std::list<int> some_list;
std::mutex some_mutex;

void add_to_list(int new_value)
{
    std::lock_guard<std::mutex> guard(some_mutex);
    some_list.push_back(new_value);
}
bool list_contains(int value_to_find)
{
    std::lock_guard<std::mutex> guard(some_mutex);
    return std::find(some_list.begin(),some_list.end(),value_to_find)
        != some_list.end();
}

#include <iostream>

int main()
{
    add_to_list(42);
    std::cout<<"contains(1)="<<list_contains(1)<<", contains(42)="<<list_contains(42)<<std::endl;
}
/*线程间共享数据:
当访问共享数据前,使用互斥量将相关数据锁住,再当访问结束后,再将数据解锁。线程库
需要保证,当一个线程使用特定互斥量锁住共享数据时,其他的线程想要访问锁住的数据,
都必须等到之前那个线程对数据进行解锁后,才能进行访问。这就保证了所有线程能看到共
享数据,而不破坏不变量。*/


/*
 C++中通过实例化 	std::mutex	 创建互斥量,通过调用成员函数lock()进行上锁,unlock()进行
解锁。不过,不推荐实践中直接去调用成员函数,因为调用成员函数就意味着,必须记住在
每个函数出口都要去调用unlock(),也包括异常的情况。C++标准库为互斥量提供了一个RAII
语法的模板类 	std::lack_guard	 ,其会在构造的时候锁住提供的互斥量,并在析构的时候进行
解锁,从而保证了一个已锁的互斥量总是会被正确的解锁。*/