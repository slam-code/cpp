#include <iostream>
#include <functional>
using namespace std;
//可以用function取代函数指针。因为它可以保存函数延迟执行，所以比较适合作
//为回调函数也可以把它看做类似于c#中特殊的委托，只有一个成员的委托。
typedef std::function<void()> fun_def;
void func()
{
	cout<<"func...\n";
}
struct A
{
	explicit A(std::function<void()>& f)
	:m_callback(f)
	{
		cout<<"构造函数...";
	};

	void Notify(){
		cout<<"Notify()... ";
		m_callback();//回调到上层
	}

	fun_def m_callback;

};

int main()
{
	fun_def func_=func;
	A a(func_);
	a.Notify();
}