#include "Prototype.h"
#include "iostream"

using namespace std;

////Prototype
Prototype::Prototype()
{
    cout<<"Prototype"<<endl;
}

Prototype::~Prototype()
{
    cout<<"~Prototype"<<endl;
}

//ConcretePrototype1
ConcretePrototype1::ConcretePrototype1()
{
    cout<<"ConcretePrototype1"<<endl;
}

ConcretePrototype1::~ConcretePrototype1()
{
    cout<<"~ConcretePrototype1"<<endl;
}

ConcretePrototype1::ConcretePrototype1(const ConcretePrototype1& cp)
{
    cout<<"ConcretePrototype1 copy"<<endl;
}

Prototype* ConcretePrototype1::Clone() const
{
    return new ConcretePrototype1(*this);
}

//ConcretePrototype2
ConcretePrototype2::ConcretePrototype2()
{
    cout<<"ConcretePrototype2"<<endl;
}

ConcretePrototype2::~ConcretePrototype2()
{
    cout<<"~ConcretePrototype2"<<endl;
}

ConcretePrototype2::ConcretePrototype2(const ConcretePrototype2& cp)
{
    cout<<"ConcretePrototype2 copy"<<endl;
}

Prototype* ConcretePrototype2::Clone() const
{
    return new ConcretePrototype2(*this);
}


int main()
{
    /*原型模式作用：用原型实例指定创建对象的种类，并且通过拷贝这些原型创建新的对象。
      Prototype模式重在从自身复制自己创建新类，隐藏（不需知道）对象创建的细节
    */

    /*1、用原型实例p1指定创建对象的种类ConcretePrototype1 */
    Prototype* p1 = new ConcretePrototype1();

    /*2、通过拷贝这些原型创建新的对象 */
    Prototype* p2 = p1->Clone();

    cout<< "------------------------" << endl;

    Prototype* p3 = new ConcretePrototype2();
    Prototype* p4 = p3->Clone();

    cout<< "------------------------" << endl;

    delete p1;
    delete p2;
    cout<< "------------------------" << endl;

    delete p3;
    delete p4;

    return 0;
}

/*
Prototype模式和Builder模式、AbstractFactory模式都是通过一个类（对象实例）来专门负责对象的创建工作（工厂对象），
它们之间的区别是：Builder模式重在复杂对象的一步步创建（并不直接返回对象），AbstractFactory模式重在产生多个相互依赖类的对象，
而Prototype模式重在从自身复制自己创建新类。
*/
//http://www.cnblogs.com/jiese/p/3164428.html