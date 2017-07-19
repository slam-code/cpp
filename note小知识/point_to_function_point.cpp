#include <iostream>
#include <stdlib.h>
using namespace std;
/* Readable!!! */
typedef int func(int);
//等同于
typedef int (*func2)(int);
typedef func* func_ptr;
typedef func_ptr* func_ptr_ptr;

//int **p(int); 小括号的优先级最高：**p(int)实际上是先执行 p(int) 的，所以，这个定义
//就是 **p(int) 是个整数，所以 *p(int) 就是整数的指针，而p(int) 就是指针的指针，
//所以p就是函数的指针（实际上最后一步是个语法糖。https://www.zhihu.com/question/38955439
func_ptr_ptr p;


//另一种c++ 11 的方法
int f(int i){ cout << i << endl; return 0; }

int main(int argc, char const *argv[])
{
	

	int (*p)(int) = f;
	decltype(p)* p2 = &p;
	(*p2)(1024);
	

	return 0;
}