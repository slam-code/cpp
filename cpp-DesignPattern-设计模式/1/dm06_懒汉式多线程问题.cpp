// 懒汉式多线程问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "windows.h"
#include "winbase.h"
#include <process.h>
#include "iostream"


#include <iostream>
using namespace std;

// 构造函数不是线程安全函数
class Singelton
{
private:
	Singelton()
	{
		cout<<"Singelton构造函数begin"<<endl;
		Sleep(1000);
		cout<<"Singelton构造函数end"<<endl;
	}

public:
	static Singelton *getSingelton()
	{
		if (single == NULL) //需要判断
		{
			count ++; 
			single = new Singelton();
		}
		return single;
	}

	static Singelton *releaseSingelton()
	{
		if (single != NULL) //需要判断
		{
			delete single;
			single = NULL;
		}
		return single;
	}
	static void pirntS() //测试函数
	{
		cout<<"Singelton printS test"<<endl;
	}

private:
	static Singelton *single;
	static int count ;
};

//note 静态变量类外初始化  //懒汉式
Singelton *Singelton::single = NULL;
int Singelton::count = 0;

void main11()
{
	Singelton *s1 = Singelton::getSingelton();
	Singelton *s2 = Singelton::getSingelton();
	if (s1 == s2)
	{
		cout<<"ok....equal"<<endl;
	}
	else
	{
		cout<<"not.equal"<<endl;
	}
	cout <<"hello...."<<endl;
	system("pause");
}

void MyThreadFunc (void *)
{
	//cout << "我是线程体 ...." << endl;
	cout << "我是线程体 ....\n";
	Singelton::getSingelton()->pirntS();
}
int _tmain(int argc, _TCHAR* argv[])
{
	//main11();
	HANDLE hThread[10];

	for (int i=0; i<3; i++)
	{
		hThread[i] = (HANDLE)_beginthread (MyThreadFunc, 0, NULL);
	}

	for (int i=0; i<3; i++)
	{
		WaitForSingleObject( hThread[i], INFINITE );	
	}
		
	cout << "hello" << endl;
	system("pause");
	return 0;
}

