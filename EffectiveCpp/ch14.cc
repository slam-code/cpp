

#include <all.h>
#define  Mutex pthread_mutex_t
#define lock pthread_mutex_lock
#define unlock pthread_mutex_unlock

/*
 * 在析构函数中管理资源
 * */
class Uncopyable
{
protected:
    Uncopyable()
    {}

    ~Uncopyable()
    {}

private:
    Uncopyable(const Uncopyable &);

    Uncopyable &operator=(const Uncopyable &);
};



class Lock : private  Uncopyable
{
public:
    explicit Lock(Mutex *pm) : mutexPtr(pm)
    {
        lock(mutexPtr);
    };

    ~Lock()
    {
        unlock(mutexPtr);
    }

private:
    Mutex *mutexPtr;
};

void f14()
{
    Mutex m;
    //Lock m1(&m);//禁止复制

}

int main()
{

    f14();
    return 0;
}
