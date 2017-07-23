#include "gtest/gtest.h"
#include "inc.h"
#include <functional>
#include <algorithm>

NS_BEGIN(elloop);

using namespace std;
using namespace std::placeholders;


// 定义一个类Foo用来测试，适配其成员函数
// 其中函数pln(x)是输出x，并换行的意思； 
class Foo
{
public:
    // 无参数member function
    void print() { pln(a_); }   

    // 接受一个参数的member function
    void print2(int i) 
    {
        pln(a_);
        pln(i);
    }

    int a_{ 100 };
};



//----------------------- c++98 mem_fun and c++11 mem_fn -----------------------
BEGIN_TEST(FunctorTest, Mem_FunTest, @);

// 1. mem_fun is for a pointer to an obj.
// 定义一个容器，存入几个Foo*, 然后使用mem_fun来取指针并绑定到Foo的成员函数
vector<Foo*> fpv;
fpv.push_back(new Foo());
fpv.push_back(new Foo());
fpv.push_back(new Foo());
fpv.push_back(new Foo());

for_each(fpv.begin(), fpv.end(), mem_fun(&Foo::print));
cr;

// mem_fun_ref用来绑定的target应该为Foo对象，而不是指针
//for_each(fpv.begin(), fpv.end(), mem_fun_ref(&Foo::print));   // error. 

for_each(fpv.begin(), fpv.end(), bind(&Foo::print, _1));    // also can use bind
cr;

// 如果成员函数接受额外参数（不仅仅是对象本身）, 那么mem_fun就无能为力了，要用bind
//for_each(fpv.begin(), fpv.end(), mem_fun(&Foo::print2, 10));
for_each(fpv.begin(), fpv.end(), bind(&Foo::print2, _1, 10)); // must use bind


// 2. mem_fun_ref is for obj.
vector<Foo> fv;
fv.push_back(Foo());
fv.push_back(Foo());
fv.push_back(Foo());
fv.push_back(Foo());

for_each(fv.begin(), fv.end(), mem_fun_ref(&Foo::print));
cr;

// mem_fun 不能用来绑定对象.
// for_each(fv.begin(), fv.end(), mem_fun(&Foo::print));    // error.

for_each(fv.begin(), fv.end(), bind(&Foo::print, _1));      // bind也可以
cr;

// 如果成员函数接受额外参数（不仅仅是对象本身）, 那么mem_fun就无能为力了，要用bind
//for_each(fv.begin(), fv.end(), mem_fun_ref(&Foo::print2, 10));

for_each(fv.begin(), fv.end(), bind(&Foo::print2, _1, 10)); // bind可以有很多参数


// 3. mem_fn既可以用于指针、引用，还可以用于对象本身，因此在C++11中使用mem_fn可以替代mem_fun和mem_fun_ref.
for_each(fpv.begin(),   fpv.end(),  mem_fn(&Foo::print));       // ptr
for_each(fv.begin(), fv.end(), mem_fn(&Foo::print));            // obj

//for_each(fv.begin(), fv.end(), mem_fn(&Foo::print2, 10));
for_each(fv.begin(), fv.end(), bind(&Foo::print2, _1, 10)); //must use bind

Foo foo;
Foo &foo_ref = foo;
mem_fn(&Foo::print)(foo_ref);                                   // ref


// clear pointers.
for_each(fpv.begin(), fpv.end(), [&](Foo* foo)
{
    delete foo;
    foo = nullptr;
});

END_TEST;




NS_END(elloop);
