
#include <boost/thread/shared_mutex.hpp>
#include <map>
#include <string>
#include <mutex>
//std::shared_lock(C++14)	用于管理可转移和共享所有权的互斥对象。
class dns_entry
{};
/*http://www.linuxidc.com/Linux/2011-07/39215p11.htm
 * http://blog.csdn.net/jongden/article/details/25800365
shared_lock是read lock。被锁后仍允许其他线程执行同样被shared_lock的代码。这是一般做读操作时的需要。

unique_lock是write lock。被锁后不允许其他线程执行被shared_lock或unique_lock的代码。
 在写操作时， 一般用这个，可以同时限制unique_lock的写和share_lock的读。
 boost::shared_lock 类型的非独占锁可以在线程只对某个资源读访问的情况下使用。一个线程修改的资源需要写访问，
 因此需要一个独占锁。 这样做也很明显：只需要读访问的线程不需要知道同一时间其他线程是否访问。
 因此非独占锁可以共享一个互斥体。
 * */
class dns_cache
{
    std::map<std::string,dns_entry> entries;
    boost::shared_mutex entry_mutex;
public:
    dns_entry find_entry(std::string const& domain)
    {
        boost::shared_lock<boost::shared_mutex> lk(entry_mutex);
        //boost::mutex为独占互斥类，boost::shared_mutex为共享互斥类。
        std::map<std::string,dns_entry>::const_iterator const it=
            entries.find(domain);
        return (it==entries.end())?dns_entry():it->second;
    }
    void update_or_add_entry(std::string const& domain,
                             dns_entry const& dns_details)
    {
        std::lock_guard<boost::shared_mutex> lk(entry_mutex);
        entries[domain]=dns_details;
    }
};

int main()//保护很少更新的数据结构
{
    std::cout<<"3.13 boost ok ";
}

/*http://en.cppreference.com/w/cpp/thread/shared_lock
 * 	std::mutex来保护数据结构,这的确有些反应过度,
 * 这里需要另一种不同的互斥量。这种新的互斥量常被称为“读者-写者锁”(reader-writer	mutex),
 * 因为其允许两中不同的使用方式:一个“作者”线程独占访问和共享访问,让多个“读者”线程并发访问。
 * */

/*比起使用std::mutex实例进行同步,不如使用boost::shared_mutex来做同步。对于更新操作,可以使
用std::lock_guard<boost::shared_mutex>和std::unique_lock<boost::shared_mutex>进行上锁,
 作为std::mutex的替代方案。与std::mutex所做的一样,这就能保证更新线程的独占访问。
 其他线程不需要去修改数据结构,其实现可以使用boost::shared_lock<boost::shared_mutex>获取共享访问权。
 这与使用	std::unique_lock一样,除非多线要在同时得到同一个 	boost::shared_mutex 上有共享锁。
 唯一的限制就是,当任一线程拥有一个共享锁时,这个线程就会尝试获取一个独占锁,直到其他线程放弃他们的
锁;同样的,当任一线程拥有一个独占锁是,其他线程就无法获得共享锁或独占锁,直到第
一个线程放弃其拥有的锁。*/

/*
在清单3.13中,find_entry()使用了 	boost::shared_lock<>实例来保护其共享和只读权限;这
就使得,多线程可以同时调用find_entry(),且不会出错。

另一方面,update_or_add_entry()使用std::lock_guard<>对象,当表格需要更新时,为其提供独占访问权限;
在update_or_add_entry()函数调用时,独占锁会阻止其他线程对数据结构进行修改,
并且这些线程在这时,也不能调用find_entry()。
 */

/*
简单的说：

shared_lock是read lock。被锁后仍允许其他线程执行同样被shared_lock的代码。这是一般做读操作时的需要。

unique_lock是write lock。被锁后不允许其他线程执行被shared_lock或unique_lock的代码。
在写操作时，一般用这个，可以同时限制unique_lock的写和share_lock的读。
 */