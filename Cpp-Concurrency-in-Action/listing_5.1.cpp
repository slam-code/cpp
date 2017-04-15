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