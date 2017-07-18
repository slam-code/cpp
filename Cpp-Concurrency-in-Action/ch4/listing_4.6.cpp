#include <iostream>
#include <future>

int find_the_answer_to_ltuae()
{
    return 42;
}

void do_other_stuff()
{}

//future:针对一次性事件

/*std::async启动一个异步任务，返回一个std::future对象，此对象持有最终的返回结果。可用.get()获取结果
当你需要这个值时,你只需要调用这个对象的get()成员函数;在“期望”状态为就绪之前调用get()的线程阻塞*/


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