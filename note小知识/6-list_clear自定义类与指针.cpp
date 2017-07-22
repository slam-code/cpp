#include <iostream>
#include <vector>
#include <zconf.h>
#include <list>
using namespace std;

class test
{
public:
	test(int i_ ){
		i=i_;
		cout<<"test() "<<i<<"...\n";
	};
	~test(){
		cout<<"~test() "<<i<<"...\n";
	};
	
	int i;
};

int main(int argc, char const *argv[])
{
	

	list<test*> plisttest;

/*	plisttest.push_back(new test(1));

	plisttest.push_back(new test(2));

	plisttest.push_back(new test(3));*/

	/*plisttest.clear();//没有调用test的析构函数.内存泄露。

	cout<<plisttest.size()<<endl;
*/


	plisttest.push_back(new test(1));

	plisttest.push_back(new test(2));

	plisttest.push_back(new test(3));

	int len=plisttest.size();
	while(len>0)
	{

		delete plisttest.front();//不再泄露内存。
		plisttest.pop_front();
		--len;
	}
	cout<<plisttest.size()<<endl;

	return 0;
}
// g++ list_clear.cpp  -g ... valgrind ./a.out
// 自定义类会调用析构函数。但是裸指针不会delete.
