
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
unique_lock是write lock。被锁后不允许其他线程执行被shared_lock或unique_lock的代码。在写操作时，
 一般用这个，可以同时限制unique_lock的写和share_lock的读。
 boost::shared_lock 类型的非独占锁可以在线程只对某个资源读访问的情况下使用。一个线程修改的资源需要写访问，
 因此需要一个独占锁。 这样做也很明显：只需要读访问的线程不需要知道同一时间其他线程是否访问。 因此非独占锁可以共享一个互斥体。
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

int main()
{
    std::cout<<"3.13 boost ok ";
}
