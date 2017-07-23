#include <iostream>
#include <functional>
using namespace std;
///function还可以作为函数入参，这样可以在函数外部控制函数的内部行为了，让我们的函数变得更加灵活。
/*void f()
{
	cout<<"f()...\n";
}*/

typedef std::function<void(int)> func_def;
void Foo(int x, std::function<void(int)>& f)
{
	if(x%2==0)
		{
			cout<<"x%2==0,f(x)= ";
			f(x);
		}
	else
		cout<<"x%2 !=0  x= "<<x<<endl;
}

void G(int x)
{
	cout<<"G(x),x= "<<x<<endl;
}

void H(int x)
{
	cout<<"H(x),x+2="<<x+2<<endl;
}

void TestFoo()
{
	///使用auto的话，无法通过编译
	func_def f = std::bind(G, std::placeholders::_1); 
	Foo(4, f);
	Foo(5, f);

//在Foo函数外面更改f的行为
	f = std::bind(H, std::placeholders::_1);
	Foo(4, f);
	Foo(5, f);
}

int main(int argc, char const *argv[])
{
	TestFoo();
	return 0;
}