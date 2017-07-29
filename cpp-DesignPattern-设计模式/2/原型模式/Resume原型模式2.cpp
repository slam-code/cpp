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

解决的问题：
用原型实例指定创建对象的种类，并且通过拷贝这些原型创建新的对象。这个其实和C++的拷贝构造函数的作用是一致的，实际上就是动态抽取当前对象运行时的状态。
拷贝构造函数也能做到上述要求．
客户（Client）角色：客户类提出创建对象的请求。
抽象原型（Prototype）角色：这是一个抽象角色，通常由一个C#接口或抽象类实现。此角色给出所有的具体原型类所需的接口。在C#中，抽象原型角色通常实现了ICloneable接口。
具体原型（Concrete Prototype）角色：被复制的对象。此角色需要实现抽象原型角色所要求的接口。



*/