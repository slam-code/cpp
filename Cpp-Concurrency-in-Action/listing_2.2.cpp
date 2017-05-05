include <thread>

void do_something(int& i)
{
    printf("i= %d ,",i);
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


void do_something_in_current_thread()
{}

/*避免应用被抛出的异常所终止,就需要作出一个决定。通常,当在无异常的情况下使用join()时,
 需要在异常处理过程中调用join(),从而避免生命周期的问题。
 */
void f()
{
    int some_local_state=0;
    func my_func(some_local_state);
    std::thread t(my_func);
    try
    {
        do_something_in_current_thread();
    }
    catch(...)//使用了 	try/catch	 块确保访问局部变量的线程退出后,函数才结束。
    {
        t.join();
        throw;
    }
    t.join();
}

int main()
{
    f();
}

/*
调用join()的行为,清理了线程相关的存储部分,这样 	std::thread	 对象将不再与已经完成的线程有任何关联。
这意味着,只能对一个线程使用一次join();一旦已经使用过join(), std::thread对象就不能再次加入了,
当对其使用joinable()时,将返回否(false)。
 * */