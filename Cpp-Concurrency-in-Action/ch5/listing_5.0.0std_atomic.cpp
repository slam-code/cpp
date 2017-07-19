
#include <atomic>
/*
 原子类型对象的主要特点就是从不同线程访问不会导致数据竞争(data race)。
 因此从不同线程访问某个原子对象是良性 (well-defined) 行为,
 而通常对于非原子类型而言，并发访问某个对象如果不做任何同步操作会导致未定义 (undifined) 行为发生。
 C++11 标准中的基本 std::atomic 模板定义如下：
 */
template < class T > struct atomic {
    bool is_lock_free() const volatile;
    bool is_lock_free() const;
    void store(T, memory_order = memory_order_seq_cst) volatile;
    void store(T, memory_order = memory_order_seq_cst);
    T load(memory_order = memory_order_seq_cst) const volatile;
    T load(memory_order = memory_order_seq_cst) const;
    operator  T() const volatile;
    operator  T() const;
    T exchange(T, memory_order = memory_order_seq_cst) volatile;
    T exchange(T, memory_order = memory_order_seq_cst);
    bool compare_exchange_weak(T &, T, memory_order, memory_order) volatile;
    bool compare_exchange_weak(T &, T, memory_order, memory_order);
    bool compare_exchange_strong(T &, T, memory_order, memory_order) volatile;
    bool compare_exchange_strong(T &, T, memory_order, memory_order);
    bool compare_exchange_weak(T &, T, memory_order = memory_order_seq_cst) volatile;
    bool compare_exchange_weak(T &, T, memory_order = memory_order_seq_cst);
    bool compare_exchange_strong(T &, T, memory_order = memory_order_seq_cst) volatile;
    bool compare_exchange_strong(T &, T, memory_order = memory_order_seq_cst);
    atomic() = default;
    constexpr atomic(T);
    atomic(const atomic &) = delete;
    atomic & operator=(const atomic &) = delete;
    atomic & operator=(const atomic &) volatile = delete;
    T operator=(T) volatile;
    T operator=(T);
};


/*如果对象不是一个原子类型,你必要确保有足够的同步操作,来确定每个线程都遵守了变量的修改顺序。*/