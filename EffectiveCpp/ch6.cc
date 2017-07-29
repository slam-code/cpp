
#include "all.h"

/*
 * 若不想使用编译器自动生成的函数，就该明确拒绝。
 * */
class Home
{
public:

private:
    Home(const Home &); //声明为private，且不实现，则等效于删除该函数
    Home &operator=(const Home);
};

//基类
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

//派生类
class Homes : private Uncopyable
{
    //无法调用copy和 =了
};


int main()
{


    return 0;
}