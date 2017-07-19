#include <atomic>
class spinlock_mutex //自旋锁的简单实现
{
    std::atomic_flag flag;
public:
    spinlock_mutex():
        flag(ATOMIC_FLAG_INIT) //初始化标志是“ clear 状态”，互斥量处于解锁状态
    {}
    void lock()//上锁，一直死循环，直到flag.test_and_set()为false。
    {
        while(flag.test_and_set(std::memory_order_acquire))
            ;//自旋状态
    }
    void unlock()
    {
        flag.clear(std::memory_order_release);//使用释放语义清除标志
    }
};

/*
 <atomic> 头文件中最简单的原子类型: atomic_flag。atomic_flag 一种简单的原子布尔类型，
只支持两种操作，test-and-set 和 clear。
std::atomic_flag 构造函数如下：
atomic_flag() noexcept = default;
atomic_flag (const atomic_flag&T) = delete;
std::atomic_flag 只有默认构造函数，拷贝构造函数已被禁用，
因此不能从其他的 std::atomic_flag对象构造一个新的 std::atomic_flag 对象。

如果在初始化时没有明确使用 ATOMIC_FLAG_INIT初始化，那么新创建的 std::atomic_flag 对象的状态是未指定的
(unspecified)(既没有被 set 也没有被 clear。)
另外，atomic_flag不能被拷贝，也不能 move 赋值。
ATOMIC_FLAG_INIT: 如果某个 std::atomic_flag 对象使用该宏初始化，那么可以保证该std::atomic_flag 对象在创建时处于 clear 状态。
 * */


/*
自旋锁与互斥锁有点类似，只是自旋锁不会引起调用者睡眠，如果自旋锁已经被别的执行单元保持，调用者就一直循环在那里看是 否该自旋锁的保持者已经释放了锁，”自旋”一词就是因此而得名。其作用是为了解决某项资源的互斥使用。因为自旋锁不会引起调用者睡眠，所以自旋锁的效率远 高于互斥锁。虽然它的效率比互斥锁高，但是它也有些不足之处：

1)旋锁一直占用CPU，他在未获得锁的情况下，一直运行－－自旋，所以占用着CPU，如果不能在很短的 时 间内获得锁，这无疑会使CPU效率降低。
2)在用自旋锁时有可能造成死锁，当递归调用时有可能造成死锁，调用有些其他函数也可能造成死锁.

3)因此我们要慎重使用自旋锁，自旋锁只有在内核可抢占式或SMP的情况下才真正需要，在单CPU且不可抢占式的内核下，自旋锁的操作为空操作。自旋锁适用于锁使用者保持锁时间比较短的情况下。
*/