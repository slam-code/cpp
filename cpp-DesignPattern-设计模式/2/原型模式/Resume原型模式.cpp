#include<iostream>
#include<string>
/*
Prototype原型类，声明一个克隆自身的接口

ConcretePrototype具体原型类，实现一个克隆自身的操作

Client 让一个原型类对象克隆自身（执行的是深拷贝），从而创建出一个新的对象，使克隆对象不与原有的对象相关联，也就是说，
原对象和克隆对象是两个完全不同的对象。

 

关于简历原型的具体实现

在C++中没有专门的接口，我们只有定义抽象类相当于接口的功能。

 

由于在Resume中没有ConcretePrototype，所以这里就不定义具体类了，也可以说把Prototype和ConcretePrototype类合并成一个Resume类。
*/
using namespace std;
//简历--既是原型类也是具体类
class Resume
{
private:
	string name;
	string sex;
	string age;
	string timeArea;
	string company;
public:
	Resume(string n) :name(n)
	{}
	//设置个人信息
	void setPersionalInfo(string _sex, string _age)
	{
		sex = _sex;
		age = _age;
	}

	//设置工作经历
	void setWorkExperience(string _timeArea, string _company)
	{
		timeArea = _timeArea;
		company = _company;
	}

	//显示
	void display()
	{
		cout << name << " 的基本信息如下：" << endl;
		cout << "性别：" << sex << endl;
		cout << "年龄：" << age << endl;
		cout << "工作经历：" << timeArea << " " << company << endl;
	}
	Resume* clone()
	{
		Resume *b=0;
		b = new Resume(this->name);
		b->setPersionalInfo(sex,age);
		b->setWorkExperience(timeArea,company);
		return b;
	}

};

//客户端调用代码
int main()
{
	Resume* a = new Resume("张三");
	a->setPersionalInfo("男", "29");
	a->setWorkExperience("2008-2010", "XX公司");

	Resume* b = a->clone();
	b->setWorkExperience("2012-2014", "YY公司");

	a->display();
	b->display();

	return 0;
}

/*
以上运行结果没有任何问题，是我们想要的结果。

如果客户端这样写：则达不到预期效果
/*
int main()  
{  
    Resume* a = new Resume("张三");  
    a->setPersionalInfo("男", "29");  
    a->setWorkExperience("2008-2010", "XX公司");  
  
    Resume* b = a;  
    b->setWorkExperience("2012-2014", "YY公司");  
  
    a->display();  
    b->display();  
  
    return 0;  
}  

/*
解释：只对指针进行简单拷贝（浅拷贝），而不对指针所指向的对象进行拷贝，则两个指针就是指向同一个内存空间，共享同一个内存对象。
改变任何一个对象，另一个对象也会跟着发生变化。

我们的目的其实就是拷贝指针对象所指向的对象（深拷贝），而不是简单的拷贝指向对象的指针。所以可以利用clone方法实现这一功能。

原型模式中的clone函数就像C++中的copy构造函数或copy赋值运算符的功能。但定义一个clone函数会更灵活的拷贝指针或引用。
copy构造函数或copy赋值运算符往往是在一个对象初始化另一个对象或者把一个对象赋值给另一个对象（不是对象指针）隐式的被调用。
*/



//http://blog.csdn.net/xingkongfenqi/article/details/49929253