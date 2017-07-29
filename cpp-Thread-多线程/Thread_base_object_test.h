
#include "Thread_base_object.h"
#include <functional>
#ifndef EFFECTIVECPP_THREAD_BASE_OBJECT_TEST_H
#define EFFECTIVECPP_THREAD_BASE_OBJECT_TEST_H


Thread::Thread(const ThreadFunc &func) : func_(func), autodelete_(false) {
    cout << "thread(),";
    printf(" pid= %x\n", pthread_self());
};

Thread::~Thread() {
    cout << "~thread(),";
    printf(" pid= %x\n", pthread_self());
}

void *Thread::Thread_routine(void *arg) {
    Thread *thread = static_cast<Thread *>(arg);
    thread->Run();
    cout << "Thread_routine pid= " << pthread_self() << endl;
    if (thread->autodelete_) delete thread;
    return NULL;
}

void Thread::Run() { func_(); }

void Thread::SetAutodelete(bool autodelete) {
    autodelete_ = autodelete;
};

void Thread::Start() {
    cout << "threadid = " << threadId_ << endl;
    pthread_create(&threadId_, nullptr, Thread_routine, this);
}

void Thread::Join() {
    pthread_join(threadId_, NULL);
}

void ThreadFunc1() {
    cout << "func...\n";
}

void ThreadFunc2(int count) {
    while (count-- >= 0) {
        cout << " func2..." << count << endl;
        sleep(1);
    }
}


class Foo {
public:
    Foo(int count) : count_(count) { cout << "Foo()...\n"; }

    void MemberFun() {
        while (count_-- >= 0) {
            cout << " func3..." << count_ << endl;
            sleep(1);
        }
    }
    ~Foo(){cout<<"~Foo...\n";}

private:
    int count_;
};

namespace Thread_baseon_object {
    void f() {
        Thread t1(ThreadFunc1);
        t1.Start();
        //基于对象的编程思想
        Thread t2(bind(ThreadFunc2, 3));
        t2.Start();
        t1.Join();
        t2.Join();
        cout<<"---\n";
        Foo foo(3);
        Thread t3(boost::bind(&Foo::MemberFun,&foo));
        t3.Start();
        t3.Join();
    }
}
#endif //EFFECTIVECPP_THREAD_BASE_OBJECT_TEST_H
