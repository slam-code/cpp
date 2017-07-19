#include <iostream>
#include <future>
int N=1000000000;
int find_the_answer_to_ltuae()
{
    for (int i = 0; i <N ; ++i)
    {
        i++;
    }
    return 42;
}

void do_other_stuff()
{
    for (int i = 0; i < N; ++i)
    {
        i++;
    }
}

/*future:针对一次性事件.
 * std::async启动一个异步任务，返回一个std::future对象，
 * 此对象持有最终的返回结果。可用.get()获取结果
 * 当你需要这个值时,你只需要调用这个对象的get()成员函数;
 * 并且,在“期望”状态为就绪之前调用get()的线程阻塞*/


int main()//带返回值的后台任务,使用std::future从异步任务中获取返回值
{
    std::future<int> the_answer=std::async(find_the_answer_to_ltuae);
    do_other_stuff();
    std::cout<<"The answer is "<<the_answer.get()<<std::endl;
}

/*当等待线程只等待一次,当条件为true时,它就不会再等待条件变量了,所以一个条件变量可能并非同步机制的最好选择。
C++标准库模型将这种一次性事件称为“期望”(future)。当一个线程需要等待一个特定的一次性事件时,
在某种程度上来说它就需要知道这个事件在未来的表现形式。*/

/*在C++标准库中,有两种“期望”,使用两种类型模板实现,声明在头文件中:唯一期望(unique futures)(std::future<>)
 * 和共享期望(shared	futures)(std::shared_future<>)。这是仿照 	std::unique_ptr和std::shared_ptr	。
 * std::future 的实例只能与一个指定事件相关联,而std::shared_future的实例就能关联多个事件。*/

/*
C++标准库使用期望（future）来支持一次性事件的等待。要等待某种一次性事件的线程可以获取一个代表该该事件的期望。
这个线程可以每隔一段事件周期性的查询这个期望。
此外，这个线程也可以继续做其它的处理，直到需要等待这个一次性事件才被挂起。通过期望还可以可以传递数据。
C++标准库提供了两种期望unique future（std::future<>）和shared futures（std::shared_future<>），
都声明在<future>库头文件中。std::future实例只能关联到一个事件。
而多个std::shared_future可以关联到同一个事件。共享期望所关联的事件发生时，所有期望实例都将同时被唤醒，
而去访问这个事件。由于期望可以关联数据，所以期望都是模版类，
没有数据关联到期望时，就可以使用std::future<void>和std::shared_future<void>。
虽然期望被用于线程间通信，但是期望对象并不支持同步的访问，
我们需要使用mutex之类的机制，来保护不同线程对它们的访问。

假设我们有一个需要较长时间的计算操作，我们要使用它的计算结果，在需要这个计算结果之前，
我们可以做一些其它的操作。我们可以启动一个新的线程来做计算。std:;thread没有直接的机制来满足我们的需求。
这里可以使用std::async函数模版来实现这个功能。

std::async可以启动一个异步的线程，我们无需像使用thread一样，立即开始等待这个异步线程执行结束，
std::async会返回一个期望对象，这个对象最终会用来存储异步线程的返回结果。当我们需要这个结果时，
对期望对象调用wait就可以让线程阻塞，直到期望准备好。*/