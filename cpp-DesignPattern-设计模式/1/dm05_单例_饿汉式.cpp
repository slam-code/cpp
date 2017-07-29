
#include <iostream>
using namespace std;


//懒汉式
class Singelton
{
private:
	Singelton()
	{
		cout << "Singelton 构造函数执行" << endl;
	}
public:
	static Singelton *getInstance()
	{
		return m_psl;
	}

	static void FreeInstance()
	{
		if (m_psl != NULL)
		{
			delete m_psl;
			m_psl = NULL;
		}
	}

private:
	static Singelton *m_psl;
};

//int g_count = 0;
//饿汉式
/*
  饿汉式是线程安全的,在类创建的同时就已经创建好一个静态的对象供系统使用,以后不再改变
  懒汉式如果在创建实例对象时不加上synchronized则会导致对对象的访问不是线程安全的
  推荐使用饿汉式。
  从实现方式来讲最大的区别就是懒汉式是延时加载, 他是在需要的时候才创建对象,而饿汉式在加载类时创建实例。
*/
Singelton *Singelton::m_psl = new Singelton;//类内的数据成员可以访问私有的构造函数，而类外无法new出实例。

int  main()
{
	printf("begin()...\n");
	Singelton *p1 = Singelton::getInstance();
	Singelton *p2 = Singelton::getInstance();

	if (p1 == p2)
	{
		cout << "是同一个对象" << endl;
	}
	else
	{
		cout << "不是同一个对象" << endl;
	}
	Singelton::FreeInstance();

}

/*
1、饿汉式：在程序启动或单件模式类被加载的时候，单件模式实例就已经被创建。
2、懒汉式：当程序第一次访问单件模式实例时才进行创建。
如何选择：如果单件模式实例在系统中经常会被用到，饿汉式是一个不错的选择。
反之如果单件模式在系统中会很少用到或者几乎不会用到，那么懒汉式是一个不错的选择。

 */