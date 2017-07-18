//
// Created by shen on 16-11-6.
//
template <class T> struct atomic<T*> {
    bool is_lock_free() const volatile;
    bool is_lock_free() const;

    void store(T*, memory_order = memory_order_seq_cst) volatile;
    void store(T*, memory_order = memory_order_seq_cst);

    T* load(memory_order = memory_order_seq_cst) const volatile;
    T* load(memory_order = memory_order_seq_cst) const;

    operator T*() const volatile;
    operator T*() const;

    T* exchange(T*, memory_order = memory_order_seq_cst) volatile;
    T* exchange(T*, memory_order = memory_order_seq_cst);

    bool compare_exchange_weak(T*&, T*, memory_order, memory_order) volatile;
    bool compare_exchange_weak(T*&, T*, memory_order, memory_order);

    bool compare_exchange_strong(T*&, T*, memory_order, memory_order) volatile;
    bool compare_exchange_strong(T*&, T*, memory_order, memory_order);

    bool compare_exchange_weak(T*&, T*, memory_order = memory_order_seq_cst) volatile;
    bool compare_exchange_weak(T*&, T*, memory_order = memory_order_seq_cst);

    bool compare_exchange_strong(T*&, T*, memory_order = memory_order_seq_cst) volatile;
    bool compare_exchange_strong(T*&, T*, memory_order = memory_order_seq_cst);

    T* fetch_add(ptrdiff_t, memory_order = memory_order_seq_cst) volatile;
    T* fetch_add(ptrdiff_t, memory_order = memory_order_seq_cst);

    T* fetch_sub(ptrdiff_t, memory_order = memory_order_seq_cst) volatile;
    T* fetch_sub(ptrdiff_t, memory_order = memory_order_seq_cst);

    atomic() = default;
    constexpr atomic(T*);
    atomic(const atomic&) = delete;

    atomic& operator=(const atomic&) = delete;
    atomic& operator=(const atomic&) volatile = delete;

    T* operator=(T*) volatile;
    T* operator=(T*);
    T* operator++(int) volatile;
    T* operator++(int);
    T* operator--(int) volatile;
    T* operator--(int);
    T* operator++() volatile;
    T* operator++();
    T* operator--() volatile;
    T* operator--();
    T* operator+=(ptrdiff_t) volatile;
    T* operator+=(ptrdiff_t);
    T* operator-=(ptrdiff_t) volatile;
    T* operator-=(ptrdiff_t);
};
