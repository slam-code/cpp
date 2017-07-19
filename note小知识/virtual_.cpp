#include <iostream>

class A {
public:
	A() {std::cout <<"A() \n";};
	virtual ~A() {std::cout <<"~A() \n";};
	virtual void echo() { std::cout << "A::echo" << std::endl; };
};

class B :public A {

public:
	B() {std::cout <<"B() \n";};
	~B() {std::cout <<"~B() \n";};

	virtual void echo()override { std::cout << "B::echo" << std::endl; };
    virtual void print() { std::cout << "B::print" << std::endl; };
};

#ifndef _WIN64  
typedef unsigned int  pointer;//32位指针
#else  
typedef unsigned long long pointer;//64位指针
#endif  

int main()
{
	B b;
	std::cout<<"\n";

	B* b1 = new B();

	A* a = new A();
	std::cout<<"\n";

	A *a1 = dynamic_cast <A*>(b1);
	B* b2 = dynamic_cast<B*>(a1);

	pointer vfptr_b = *(pointer*)&b;
	pointer vfptr_b1 = *(pointer*)b1;

	pointer vfptr_a = *(pointer*)a;
	pointer vfptr_a1 = *(pointer*)a1;
	pointer vfptr_b2 = *(pointer*)b2;

	std::cout
		<< vfptr_b << "\n"
		<< vfptr_b1 << "\n"
		<< vfptr_a << "\n"
		<< vfptr_a1 << "\n"
		<< vfptr_b2 << std::endl;

	return 0;
}

/**
如上代码，将对象地址强制转换为指针地址，得到vftable的地址，其中除了vfptr_a，其余对象的虚函数表的地址是一样的，说明这些对象共用了一个虚函数表。

主流 C++ 实现（gcc/clang/VC++）对于最简单的单继承且基类有虚函数的情况（非虚拟继承）的做法都差不多：
vtable 是每个 class 类型一个，不是每个对象一个。vtable 的大小（长度）跟这个 class 的虚函数总数（继承和自己新增）正相关。
vptr 是每个对象一个，vptr 大小是固定的，跟虚函数多少无关。
对象的 vptr 在构造和析构的时候可能会变，指向不同的 vtable。对象构造完就不会变了。
“只使用前一段”有可能发生，如果派生类添加了新的虚函数的话（比如 virtual void B::print()）。

*/