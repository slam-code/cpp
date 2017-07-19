////
//// Created by shen on 16-9-16.
////
//
//#include "Thread.h"
//
//    Thread::Thread() {
//    cout << "thread() , ";
//    printf(" pid= %x\n", pthread_self());
//}
//
//Thread::~Thread() {
//    cout << "~thread() , ";
//     printf(" pid= %x\n", pthread_self());
//}
//
//void Thread::Start() {
//    cout << "threadid = " << threadId_ << endl;
//    pthread_create(&threadId_, nullptr, Thread_routine, this);
//}
//
//void Thread::Join() {
//    pthread_join(threadId_, NULL);
//}
//
//void *Thread::Thread_routine(void *arg) { //静态的成员函数，不能调用非静态的成员函数（没有this指针）:即只写run()是不正确的！
//
//    Thread *thread = static_cast<Thread *>(arg); //派生类的指针，强制转换为基类指针。目的：基类指针 指向派生类对象，多态！
//    thread->Run();
//    //printf("child pid= %x \n", pthread_self());
//    if(thread->autodelete_)
//        delete thread;
//    return NULL;
//}
//
//void Thread::SetAutodelete(bool autodelete) {
//        autodelete_=autodelete;
//};
//
//
