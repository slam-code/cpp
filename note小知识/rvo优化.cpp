#include <iostream>
using namespace std;
struct Foo   
{   
	Foo() { cout << "Foo ctor" << endl; }
	Foo(const Foo&) { cout << "Foo copy ctor" << endl; }
	void operator=(const Foo&) { cout << "Foo operator=" << endl; } 
	~Foo() { cout << "Foo dtor" << endl; }
};  
Foo make_foo()   
{
	Foo f;
	cout<<"  "<<endl;
	return f;
}  

int main()
{
	make_foo();
}

/*
make_foo函数的返回对象，在linux下g++和vc++Release版本下，
不会调用拷贝构造函数，而是直接返回对象，这就叫做rvo优化。
但是vc下的debug版本没有做这个优化，读者可以自己测试一下。*/