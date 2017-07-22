#include <iostream>
#include <stdlib.h>
#include <functional>
using namespace std;

//定义func为函数
typedef int func(int);

//等价定义。
typedef int (*func2)(int);

//定义指向函数的指针
typedef func *func_ptr;
//定义指向函数指针的指针
typedef func_ptr *func_ptr_ptr;
/*
int (**p)(int);
(**p)(int)是个整数。**p 是个函数，返回一个整数。
于是 *p 是个函数的指针。 p 是个函数指针的指针。

按定义顺序解释：
int **p(int); 小括号的优先级最高：**p(int)实际上是先执行 p(int) 的，所以，这个定义
就是 **p(int) 是个整数，所以 *p(int) 就是整数的指针，而p(int) 就是指针的指针，
所以p就是函数的指针（实际上最后一步是个语法糖。
https://www.zhihu.com/question/38955439
*/
func_ptr_ptr p;


//另一种c++ 11 的方法
int f(int i)
{
    cout << i << endl;
    return 0;
}

typedef std::function<int(int)> fp;
using fp2=std::function<double(double, double)>;

int main(int argc, char const *argv[])
{

    //使用decltype()：
    int (*p)(int) = f;//p是函数指针
    decltype(p) *p2 = &p;//p2是指向函数指针的指针。
    (*p2)(1024);


    //另一种简洁的方式
    fp fp_value=f;
    auto  fpp_value=&fp_value;
    //decltype(fp_value) *fpp_value=&fp_value;
    (*fpp_value)(1024);
    return 0;
}