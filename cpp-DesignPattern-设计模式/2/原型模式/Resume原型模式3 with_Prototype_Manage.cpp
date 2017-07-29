// CplusplusPrototype.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;
//父类  
class Resume  
{  
protected:  
	char *name;  
public:  
	Resume() {}  
	virtual ~Resume() {}  
	virtual Resume* Clone() { return NULL; }  
	virtual void Set(char *n) {}  
	virtual void Show() {}  
}; 
class ResumeA : public Resume  
{  
public:  
	ResumeA(const char *str);  //构造函数  
	ResumeA(const ResumeA &r); //拷贝构造函数  
	~ResumeA();                //析构函数  
	ResumeA* Clone();          //克隆，关键所在  
	void Show();               //显示内容  
};  
ResumeA::ResumeA(const char *str)   
{  
	if(str == NULL) {  
		name = new char[1];   
		name[0] = '\0';   
	}  
	else {  
		name = new char[strlen(str)+1];  
		strcpy(name, str);  
	}  
}  
ResumeA::~ResumeA() { delete [] name;}  
ResumeA::ResumeA(const ResumeA &r) {  
	name = new char[strlen(r.name)+1];  
	strcpy(name, r.name);  
}  
ResumeA* ResumeA::Clone() {  
	return new ResumeA(*this);  
}  
void ResumeA::Show() {  
	cout<<"ResumeA name : "<<name<<endl;   
} 

class ResumeB : public Resume  
{  
public:  
	ResumeB(const char *str);  //构造函数  
	ResumeB(const ResumeB &r); //拷贝构造函数  
	~ResumeB();                //析构函数  
	ResumeB* Clone();          //克隆，关键所在  
	void Show();               //显示内容  
};  
ResumeB::ResumeB(const char *str)   
{  
	if(str == NULL) {  
		name = new char[1];   
		name[0] = '\0';   
	}  
	else {  
		name = new char[strlen(str)+1];  
		strcpy(name, str);  
	}  
}  
ResumeB::~ResumeB() { delete [] name;}  
ResumeB::ResumeB(const ResumeB &r) {  
	name = new char[strlen(r.name)+1];  
	strcpy(name, r.name);  
}  
ResumeB* ResumeB::Clone() {  
	return new ResumeB(*this);  
}  
void ResumeB::Show() {  
	cout<<"ResumeB name : "<<name<<endl;   
} 

class ResumeManager
{
private:
	vector<Resume *> mResume;
public:
	ResumeManager()
	{

	}
	void add(Resume * resume)
	{
		mResume.push_back(resume);
	}

	 Resume * get(int index) const
	{
		assert(index>=0 && index<mResume.size());
		return mResume[index];
	}
};

int main(int argc, _TCHAR* argv[])
{
	ResumeManager *manager = new ResumeManager();
	Resume *r1 = new ResumeA("A");  
    Resume *r2 = new ResumeB("B");  
	manager->add(r1);
	manager->add(r2);
    manager->get(0)->Show(); 
	manager->get(1)->Show();  
	Resume *r3 = manager->get(0)->Clone();  
    Resume *r4 = manager->get(1)->Clone(); 

    //删除r1,r2  
    delete r1; delete r2;     
    r1 = r2 = NULL;  
    //深拷贝所以对r3,r4无影响  
    r3->Show(); r4->Show();  
    delete r3; delete r4;  
    r3 = r4 = NULL; 
	return 0;
}
/*
客户（Client）角色：客户端类向原型管理器提出创建对象的请求。
抽象原型（Prototype）角色：这是一个抽象角色，通常由一个C#接口或抽象类实现。此角色给出所有的具体原型类所需的接口。在C#中，抽象原型角色通常实现了ICloneable接口。
具体原型（Concrete Prototype）角色：被复制的对象。此角色需要实现抽象的原型角色所要求的接口。
原型管理器（Prototype Manager）角色：创建具体原型类的对象，并记录每一个被创建的对象。

*/


/*
实现要点：
1．使用原型管理器，体现在一个系统中原型数目不固定时，可以动态的创建和销毁。
2．实现克隆操作，在.NET中可以使用Object类的MemberwiseClone()方法来实现对象的浅表拷贝或通过序列化的方式来实现深拷贝，在C++中就是拷贝构造函数的作用。
3．Prototype模式同样用于隔离类对象的使用者和具体类型（易变类）之间的耦合关系，它同样要求这些“易变类”拥有稳定的接口。

效果：
1．它对客户隐藏了具体的产品类，因此减少了客户知道的名字的数目。
2． Prototype模式允许客户只通过注册原型实例就可以将一个具体产品类并入到系统中，客户可以在运行时刻建立和删除原型。
3．减少了子类构造，Prototype模式是克隆一个原型而不是请求工厂方法创建一个，所以它不需要一个与具体产品类平行的Creater类层次。
4．Portotype模式具有给一个应用软件动态加载新功能的能力。由于Prototype的独立性较高，可以很容易动态加载新功能而不影响老系统。
5．产品类不需要非得有任何事先确定的等级结构，因为Prototype模式适用于任何的等级结构
6．Prototype模式的最主要缺点就是每一个类必须配备一个克隆方法。而且这个克隆方法需要对类的功能进行通盘考虑，这对全新的类来说不是很难，但对已有的类进行改造时，不一定是件容易的事。

适用性：
1. 当一个系统应该独立于他的产品创建、构成和表示时，需要使用原型模式
2. 当要实例化的类是在运行时刻指定时，如通过动态装载
3. 为了避免创建一个与产品类层次平行的工厂类层次时
4. 当一个类的实例只能有几个不同状态组合中的一种时，建立相应数目的原型并克隆他们可能比每次用合适的状态手工实例化该类更方便一些。

*/

//http://blog.csdn.net/lcl_data/article/details/8764228