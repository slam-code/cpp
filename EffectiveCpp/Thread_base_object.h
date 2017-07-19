//
// Created by shen on 16-9-16.
//

#ifndef EFFECTIVECPP_THREAD_BASE_OBJECT_H
#define EFFECTIVECPP_THREAD_BASE_OBJECT_H

#include <pthread.h>
#include <iostream>
#include <boost/function.hpp>

#include <boost/bind.hpp>

using namespace std;
using namespace boost;
typedef boost::function<void()> ThreadFunc;

//基于对象的编程思想
class Thread {
public:

    explicit Thread(const ThreadFunc &func);

    ~Thread();

    void Start();

    void Join();

    void SetAutodelete(bool autodelete);

private:
    void Run();//没有虚函数，不是继承关系，而是注册，回调！

    static void *Thread_routine(void *arg);

    pthread_t threadId_;
    ThreadFunc func_;
    bool autodelete_ = false;
};

#endif //EFFECTIVECPP_THREAD_BASE_OBJECT_H
