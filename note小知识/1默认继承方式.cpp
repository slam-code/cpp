#include<iostream>
class A
{
public:
A(){a = 3;}
int a;
};

class B : A
{};

struct C
{public:
	C(){ cc = 3;}
	int cc;

};

class D:C
{
};

using namespace std;
int main()
{
B b;
cout << b.a << endl;	//'A::a' not accessible because 'B' uses 'private' to inherit from 'A'

//class默认是private，struct默认是public继承
//private 继承的含义是继承功能，不继承接口。但是现在大多数的书都提倡用组合的方式来使用功能，不提倡用 private 继承，所以显得没用。
C c;
cout<<c.cc<<endl;
return 0;
}

