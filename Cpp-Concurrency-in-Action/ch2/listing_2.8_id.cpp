#include <thread>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>

std::thread::id master_thread;

void some_core_part_of_algorthm()
{
    //每个线程都要检查一下,其拥有的线程ID是否与main线程的ID相同。
    if(std::this_thread::get_id()==master_thread)
    {
        do_master_thread_work();
    }
    do_common_work();
}

int main()
{


}
/*线程标识类型是 	std::thread::id	 ,可以通过两种方式进行检索。第一种,可以通过调用std::thread对象的成员函数
get_id()来直接获取。如果std::thread对象没有与任何执行线程相关联, 	get_id()将返回std::thread::type 默认构造值,
这个值表示“没有线程”。第二种,当前线程中调用 	std::this_thread::get_id()
*/