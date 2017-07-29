#include <pthread.h> //
#include <unistd.h>

#include <stdio.h>
/*线程不像进程，一个进程中的线程之间是没有父子之分的，都是平级关系。即线程都是一样的, 退出了一个不会影响另外一个。
  但是所谓的"主线程"main,其入口代码是类似这样的方式调用main的：exit(main(...))。
  main执行完之后, 会调用exit()。
  exit() 会让整个进程over终止，那所有线程自然都会退出。*/
int i=0;
void* func(void* arg)
{
    pthread_t main_tid = *static_cast<pthread_t*>(arg);
    
    while (i<50)
    {
        i++;
        printf("child loops\n %d \n",i);
        usleep(100000);
        if(i>30)
            pthread_cancel(main_tid);
    }
    return NULL;
}

int main(int argc, char* argv[])
{
    pthread_t main_tid = pthread_self();
    pthread_t tid = 0;
    pthread_create(&tid, NULL, func, &main_tid);
    while (i<20)
    {
        i++;
        printf("main loops, %d \n",i);
        usleep(100000);

    }
    sleep(1);
    printf("main exit\n");
    pthread_exit(NULL);
    /*运行上面的代码，会发现程序在打印一定数量的「child loops」和一句「main exit」之后退出，并且在退出之前的最后一句打印是「main exit」。*/

    return 0;
}

/*主线程先退出，子线程继续运行的方法:
 在进程主函数（main()）中调用pthread_exit()，只会使主函数所在的线程（可以说是进程的主线程）退出；
 而如果是return，编译器将使其调用进程退出的代码（如_exit()），从而导致进程及其所有线程结束运行。
 main()中调用了pthread_exit后，导致住线程提前退出，其后的exit()无法执行了，所以要到其他线程全部执行完了，整个进程才会退出。
 */
