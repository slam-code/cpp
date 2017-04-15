#include <iostream>
#include <future>

int find_the_answer_to_ltuae()
{
    return 42;
}

void do_other_stuff()
{}

//future:针对一次性事件

//std::async启动一个异步任务，返回一个std::future对象，此对象持有最终的返回结果。可用.get()获取结果
int main()
{
    std::future<int> the_answer=std::async(find_the_answer_to_ltuae);
    do_other_stuff();
    std::cout<<"The answer is "<<the_answer.get()<<std::endl;
}
