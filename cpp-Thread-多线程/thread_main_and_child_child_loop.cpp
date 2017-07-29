#include <pthread.h> //主线程退出对子线程的影响
#include <unistd.h>

#include <stdio.h>

int i=0;
void* func(void* arg)
{
    pthread_t main_tid = *static_cast<pthread_t*>(arg);
     pthread_cancel(main_tid); //把主线程的线程号传给子线程，在子线程中通过pthread_cancel终止主线程使其退出。
    while (i<50)
    {
        i++;
        printf("child loops\n %d \n",i);
        usleep(100000); //子线程终止了主线程后进入了死循环while中，所以程序看起来像挂起了。
           
    }
    return NULL;// 主线程被子线程终止了，但他们所依赖的进程并没有退出，所以子线程依然正常运转。
}

int main(int argc, char* argv[])
{
    pthread_t main_tid = pthread_self();
    pthread_t tid = 0;
    pthread_create(&tid, NULL, func, &main_tid);
    while (i<20)
    {
        i++;
        printf("main loops, %d \n",i);//运行程序，可以发现在打印了一定数量的「main loops」之后程序就挂起了，但却没有退出。
        usleep(100000);

    }
    sleep(1);
    printf("main exit\n"); //主线程因为被子线程终止了，所有没有看到「main exit」的打印。
/* 主线程中的main函数执行完ruturn后弹栈，然后调用glibc库函数exit，exit进行相关清理工作后调用_exit系统调用退出该进程。*/
    return 0;
}

//一个线程的退出不会影响另外一个线程。但是进程结束，所有线程也就结束了，所有资源会被回收。
