#include <deque>
#include <mutex>
#include <future>
#include <thread>
#include <utility>

std::mutex m;
std::deque<std::packaged_task<void()> > tasks;

bool gui_shutdown_message_received();
void get_and_process_gui_message();

void gui_thread()
{
    while(!gui_shutdown_message_received())
    {
        get_and_process_gui_message();
        std::packaged_task<void()> task;
        {
            std::lock_guard<std::mutex> lk(m);
            if(tasks.empty())
                continue;
            task=std::move(tasks.front());
            tasks.pop_front();
        }
        task();
    }
}

std::thread gui_bg_thread(gui_thread);

template<typename Func>
std::future<void> post_task_for_gui_thread(Func f)
{
    std::packaged_task<void()> task(f);
    std::future<void> res=task.get_future();
    std::lock_guard<std::mutex> lk(m);
    tasks.push_back(std::move(task));
    return res;
}
/*这个例子使用std::packaged_task<void()>创建任务,
其包含了一个无参数无返回值的函数或可调用对象(如果当这个调用有返回值时,返回值会被丢弃)。
这可能是最简单的任务,如你之前所见,std::packaged_task也可以用于一些复杂的情况
——通过指定一个不同的函数签名作为模板参数,你不仅可以改变其返回类型(因此该类型的数据会存在期望相关的状态中),
而且也可以改变函数操作符的参数类型。这个例子可以简单的扩展成允许任务运行在图形界面线程上,
且接受传参,还有通过std::future	 返回值,而不仅仅是完成一个指标。*/