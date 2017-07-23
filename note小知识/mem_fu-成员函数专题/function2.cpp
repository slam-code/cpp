#include <iostream>
#include <functional>
using namespace std;

/*
std::function
它是函数、函数对象、函数指针、和成员函数的包装器，可以容纳任何类型的函数对象，函数指针，引用函数，成员函数的指针。
以统一的方式处理函数、函数对象、函数指针、和成员函数。
允许保存和延迟执行函数。

函数和成员函数作为function
*/
void G(){
	cout<<"G(): \n";
};
struct A
{
void H(){
	cout<<"H(): \n";
}
};

std::function<void()> f = G; //全局函数

A a;
std::function<void()> f1= std::bind(&A::H, a); //成员函数

int main()
{
	f();
	f1();
}
