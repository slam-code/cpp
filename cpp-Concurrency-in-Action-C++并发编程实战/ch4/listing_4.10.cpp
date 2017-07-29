#include <future>
//使用“承诺”解决单线程多连接问题
void process_connections(connection_set& connections)
{
    while(!done(connections))
    {
        for(connection_iterator
                connection=connections.begin(),end=connections.end();
            connection!=end;
            ++connection)
        {
            if(connection->has_incoming_data())
            {
                data_packet data=connection->incoming();
                std::promise<payload_type>& p=
                    connection->get_promise(data.id);
                p.set_value(data.payload);
            }
            if(connection->has_outgoing_data())
            {
                outgoing_packet data=
                    connection->top_of_outgoing_queue();
                connection->send(data.payload);
                data.promise.set_value(true);
            }
        }
    }
}
/*考虑一个线程处理多个连接事件,来自不同的端口连接的数据包基本上是以乱序方式进行处
理的;同样的,数据包也将以乱序的方式进入队列。在很多情况下,另一些应用不是等待数
据成功的发送,就是等待一批(新的)来自指定网络接口的数据接收成功。

std::promise<T>提供设定值的方式(类型为T),这个类型会和后面看到的std::future<T>对象相关联。
一对std::promise/std::future会为这种方式提供一个可行的机制;在期望上可以阻塞等待线程,
同时,提供数据的线程可以使用组合中的“承诺”来对相关值进行设置,以及将“期望”的状态置为“就绪”。
可以通过get_future()成员函数来获取与一个给定的std::promise相关的std::future对象,
就像是与std::packaged_task相关。当“承诺”的值已经设置完毕(使用set_value()成员函数),
对应“期望”的状态变为“就绪”,并且可用于检索已存储的值。当你在设置值之前销毁td::promise,将会存储一个异常。
在4.2.4节中,会详细描述异常是如何传送到线程的。*/