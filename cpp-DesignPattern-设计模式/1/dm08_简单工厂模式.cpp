
#include <iostream>
#include <cstring>

using namespace std;

class Fruit
{
public:
    Fruit()
    {
        cout<<"Fruit()...\n";
    }

    virtual void getFruit() = 0;

protected:
private:
};

class Banana : public Fruit
{
public:
    virtual void getFruit()
    {
        cout << "我是香蕉...." << endl;
    }
protected:
private:
};

class Apple : public Fruit
{
public:
    virtual void getFruit()
    {
        cout << "我是苹果...." << endl;
    }
protected:
private:
};


class Factory
{
public:
    Factory()
    {
        cout<<"Factory()..."<<endl;
    }

    Fruit *create(char *p)//简单工厂类聚合了所有类实例的创建方法，增加类必须修改工厂：不好。
    {

        if (strcmp(p, "banana") == 0)
        {
            return new Banana;
        }
        else if (strcmp(p, "apple") == 0)
        {
            return new Apple;
        }
        else
        {
            printf("不支持\n" ) ;
            return NULL;
        }
    }
};


int  main()
{
    Factory *f = new Factory;

    Fruit *fruit = NULL;


    //工厂生产 香蕉
    fruit = f->create("banana");
    fruit->getFruit();
    delete fruit;


    fruit = f->create("apple");
    fruit->getFruit();
    delete fruit;

    delete f;
}
/*
定义：定义一个用于创建对象的接口，让子类决定实例化哪一个类，工厂方法使一个类的实例化延迟到其子类.
 * */