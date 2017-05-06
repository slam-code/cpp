#include <mutex>
#include <iostream>

struct connection_info
{};

struct data_packet
{};

struct connection_handle
{
    void send_data(data_packet const&)
    {}
    data_packet receive_data()
    {
        return data_packet();
    }
};

struct remote_connection_manager
{
    connection_handle open(connection_info const&)
    {
        return connection_handle();
    }
} connection_manager;


class X   //使用std::call_once作为类成员的延迟初始化(线程安全)
{
private:
    connection_info connection_details;
    connection_handle connection;
    std::once_flag connection_init_flag;

    void open_connection()
    {
        connection=connection_manager.open(connection_details);
    }
public:
    X(connection_info const& connection_details_):
        connection_details(connection_details_)
    {}
    void send_data(data_packet const& data)
    {
        std::call_once(connection_init_flag,&X::open_connection,this);
        //使用open_connection函数完成初始化数据
        connection.send_data(data);
    }
    data_packet receive_data()
    {
        std::call_once(connection_init_flag,&X::open_connection,this);
        return connection.receive_data();
    }
};

/*
在这个例子中,第一个调用send_data()或receive_data()的线程完成初始化过程。使用成
员函数open_connection()去初始化数据,也需要将this指针传进去。和其在标准库中的函数
一样,其接受可调用对象,比如 	std::thread	的构造函数和 std::bind(),
通过向std::call_once()传递一个额外的参数来完成这个操作。
值得注意的是,	std::mutex和std::one_flag的实例就不能拷贝和移动,所以当你使用它们
作为类成员函数,如果你需要用到他们,你就得显示定义这些特殊的成员函数。
 */
class my_class{};
my_class& get_my_class_instance()//局部变量声明为static且以后不更新：c++11后，初始化与定义均在一个线程中发生，是线程安全的初始化。
{
    static my_class instance;
    return instance;
}
/*其中一个局部变量被声明为static类型。这种变量在声明后就已经完成初始化;
 * 对于多线程调用的函数,这就意味着这里有条件竞争——抢着去定义这个变量。
 * 在很多不支持C++11标准的编译器中,这样的条件竞争是确实存在的,因为在多线程中,
 * 每个线程都认为他们是第一个初始化这个变量线程;或一个线程对变量进行初始化,
 * 而另外一个线程要使用这个变量时,初始化过程还没完成。
 *
 * 在C++11标准中,这些问题都被解决了:
 * 初始化及定义完全在一个线程中发生,并且没有其他线程可在初始化完成前对其进行处理
*/
 //安全初始化，但极少更新：见3.13。

int main()
{
    std::cout<<"3.12 ok";
}


