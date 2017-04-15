//
// Created by shen on 16-11-6.
//
/*
 * 另外，C++11 标准库 std::atomic 提供了针对整形(integral)和指针类型的特化实现，分别定义如下：

针对整形(integal)的特化，其中 integal 代表了如下类型
 char, signed char, unsigned char, short, unsigned short, int, unsigned int,
 long, unsigned long, long long, unsigned long long, char16_t, char32_t, wchar_t：
 */
template <> struct atomic<integral> {
    bool is_lock_free() const volatile;
    bool is_lock_free() const;

    void store(integral, memory_order = memory_order_seq_cst) volatile;
    void store(integral, memory_order = memory_order_seq_cst);

    integral load(memory_order = memory_order_seq_cst) const volatile;
    integral load(memory_order = memory_order_seq_cst) const;

    operator integral() const volatile;
    operator integral() const;

    integral exchange(integral, memory_order = memory_order_seq_cst) volatile;
    integral exchange(integral, memory_order = memory_order_seq_cst);

    bool compare_exchange_weak(integral&, integral, memory_order, memory_order) volatile;
    bool compare_exchange_weak(integral&, integral, memory_order, memory_order);

    bool compare_exchange_strong(integral&, integral, memory_order, memory_order) volatile;
    bool compare_exchange_strong(integral&, integral, memory_order, memory_order);

    bool compare_exchange_weak(integral&, integral, memory_order = memory_order_seq_cst) volatile;
    bool compare_exchange_weak(integral&, integral, memory_order = memory_order_seq_cst);

    bool compare_exchange_strong(integral&, integral, memory_order = memory_order_seq_cst) volatile;
    bool compare_exchange_strong(integral&, integral, memory_order = memory_order_seq_cst);

    integral fetch_add(integral, memory_order = memory_order_seq_cst) volatile;
    integral fetch_add(integral, memory_order = memory_order_seq_cst);

    integral fetch_sub(integral, memory_order = memory_order_seq_cst) volatile;
    integral fetch_sub(integral, memory_order = memory_order_seq_cst);

    integral fetch_and(integral, memory_order = memory_order_seq_cst) volatile;
    integral fetch_and(integral, memory_order = memory_order_seq_cst);

    integral fetch_or(integral, memory_order = memory_order_seq_cst) volatile;
    integral fetch_or(integral, memory_order = memory_order_seq_cst);

    integral fetch_xor(integral, memory_order = memory_order_seq_cst) volatile;
    integral fetch_xor(integral, memory_order = memory_order_seq_cst);

    atomic() = default;
    constexpr atomic(integral);
    atomic(const atomic&) = delete;

    atomic& operator=(const atomic&) = delete;
    atomic& operator=(const atomic&) volatile = delete;

    integral operator=(integral) volatile;
    integral operator=(integral);

    integral operator++(int) volatile;
    integral operator++(int);
    integral operator--(int) volatile;
    integral operator--(int);
    integral operator++() volatile;
    integral operator++();
    integral operator--() volatile;
    integral operator--();
    integral operator+=(integral) volatile;
    integral operator+=(integral);
    integral operator-=(integral) volatile;
    integral operator-=(integral);
    integral operator&=(integral) volatile;
    integral operator&=(integral);
    integral operator|=(integral) volatile;
    integral operator|=(integral);
    integral operator^=(integral) volatile;
    integral operator^=(integral);
};
