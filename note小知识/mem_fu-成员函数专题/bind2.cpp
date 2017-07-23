//function模板类和bind模板函数，使用它们可以实现类似函数指针的功能，但却却比函数指针更加灵活，特别是函数指向类 的非静态成员函数时。
//std::function可以绑定到全局函数/类静态成员函数(类静态成员函数与全局函数没有区别),如果要绑定到类的非静态成员函数，则需要使用std::bind。
//std::bind绑定到虚函数时会表现出多态行为。
#include <iostream>
#include <functional>
using namespace std;
using namespace std::placeholders;
typedef std::function<void ()> fp;
typedef std::function<void (int)> fp_int;
void g_fun()
{
	cout<<"g_fun()"<<endl;
}
class A
{
public:
	static void A_fun_static()
	{
		cout<<"A_fun_static()"<<endl;
	}
	void A_fun()
	{
		cout<<"A_fun()"<<endl;
	}
	void A_fun_int(int i)
	{
		cout<<"A_fun_int() "<<i<<endl;
	}

	//非静态类成员，因为含有this指针，所以需要使用bind
	void init()
	{
		fp fp1=std::bind(&A::A_fun,this);
		fp1();
	}

	void init2()
	{
		typedef std::function<void (int)> fpi;
		//对于参数要使用占位符 std::placeholders::_1
		fpi f=std::bind(&A::A_fun_int,this,_1);
		f(5);
	}
};
int main()
{
	//绑定到全局函数
	fp f2=fp(&g_fun);
	f2();

	//绑定到类静态成员函数
	fp f1=fp(&A::A_fun_static);
	f1();

	A().init();
	A().init2();
	A a;
	
	fp f_out0=std::bind(&A::A_fun,a);
	f_out0();

	
	typedef std::function<void (A)> fp_;//f_out0_的类型为: void f(A)而不是fp
	fp_ f_out0_=std::bind(&A::A_fun,_1);
	f_out0_(a);

	fp_int f_out1=std::bind(&A::A_fun_int,a,_1);
	f_out1(2);

	auto f_out1_=std::bind(&A::A_fun_int,_1,_2);
	f_out1_(a,4);// error :f_out1_(a);

	return 0;
}
