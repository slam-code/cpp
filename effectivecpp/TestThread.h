////
//// Created by shen on 16-9-16.
////
//
//#ifndef EFFECTIVECPP_TESTTHREAD_H
//#define EFFECTIVECPP_TESTTHREAD_H
//
//#include <zconf.h>
//#include "Thread.h"
//
//using  namespace std;
//namespace TestThread{
//    class TestThread : public Thread {
//    public:
//        TestThread(int count) : count_(count) {
//            cout << "testthread() , ";
//            printf(" pid= %x\n", pthread_self());
//
//        };
//
//        ~TestThread() {
//            cout << "~testthread() ,";
//            printf(" pid= %x\n",(int )pthread_self());
//        };
//
//        void Run() {
//            while (count_-- >= 0) {
//                cout << "count_= " << count_ << endl;
//                sleep(1);
//            }
//        }
//
//        int count_;
//    };
//
//    void f() {
//        TestThread t(3);
//        t.Start(); //隐含的是this指针，相当于&t。通过基类指针指向派生类对象实现了：调用派生类对象实现的虚函数run()!
//        //本质是虚函数的多态。实现了虚函数具有回调功能
//        //t.Run()代替 t.Srart()是错误的，因为前者是在主线程中运行，而后者是新线程中。故将其设置为private
//        t.Join();
//
//        sleep(2);
//        cout << "t1 线程已经执行完毕，线程对象呢？^|^\n\n";//线程对象的生命周期 与 线程的生命周期不一样。
//        //线程对象仍未被销毁！
//        //实现 线程执行完毕，线程对象自动销毁?
////       //法一
//        TestThread *t2 = new TestThread(3);
//        t2->Start();
//        t2->Join();
//        delete t2;
//
//        cout << "t2 执行完毕，是否已经销毁? ^|^\n\n";
//        sleep(5);
//
//        // //法 2
//        TestThread *t3 = new TestThread(3);
//        t3->SetAutodelete(true);
//        t3->Start();
//        t3->Join();
//        cout << "t3执行完毕，是否已经销毁? ^|^ \n\n";
//        sleep(10);
//
//
//    }
//
//}
//
//
//#endif //EFFECTIVECPP_TESTTHREAD_H
