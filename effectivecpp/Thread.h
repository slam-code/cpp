////
//// Created by shen on 16-9-16.
////
//
//#ifndef EFFECTIVECPP_THREAD_H
//#define EFFECTIVECPP_THREAD_H
//
//#include <pthread.h>
//#include <iostream>
//using namespace std;
//
//class Thread{
//public:
//    Thread();
//    virtual ~Thread();
//    void Start();
//    void Join();
//    void SetAutodelete(bool autodelete);
//
//private:
//    virtual void Run()=0; //run是普通的虚成员函数，隐含的第一个参数是Thread*(this),调用的时候是 this->run();
//    static void *Thread_routine (void *arg);
//    pthread_t threadId_;
//    bool autodelete_= false;
//};
//
//
//
//#endif //EFFECTIVECPP_THREAD_H
