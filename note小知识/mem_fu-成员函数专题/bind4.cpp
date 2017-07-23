#include <iostream>
#include <functional>
using namespace std;
/*
std::bind绑定器
将函数、成员函数和闭包转成function函数对象
将多元(n>1)函数转成一元函数或者(n-1)元函数。

*/
class ReadHandler
{
public:
	ReadHandler(){};
	~ReadHandler(){};
	void ConnectPreProcess(int a)
	{
		cout<<"ConnectPreProcess(a) ,a = "<<a<<endl;
	}
	
};
void H(int a){
	cout<<"H(a),a= "<<a;
};
//绑定全局函数
auto f11 = std::bind(H, std::placeholders::_1);
//auto的类型实际上是std::function<void(int)>
ReadHandler read;
//绑定带参数的成员函数
std::function<void (int)> f_ReadHandler = std::bind(
	&ReadHandler::ConnectPreProcess,
	read,
	std::placeholders::_1);//, 	std::placeholders::_1

//三元函数转换成一元函数
int f(int a, char b , double c ){
	cout<<"a,b,c= "<<a<<" "<<b<<" "<<c<<endl;
	return a;
};
// 绑定f()函数调用的第二个和第三个参数，
// 返回一个新的函数对象为ff，它只带有一个int类型的参数
auto ff = bind(f, std::placeholders::_1, 'c', 1.2);    
//int x = ff(7); 

int main(int argc, char const *argv[])
{
	f_ReadHandler(1);
	cout<<"ff(7)= \n"<<ff(7)<<endl;
	return 0;
}