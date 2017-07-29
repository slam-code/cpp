
#include <iostream>
#include <cstdlib>

using namespace std;

//依赖(虚线): 一个类是另外一个类的函数参数或者函数返回值

class Car;

class ZhangSan
{
public:
    //依赖关系
    void GoWork(Car *p)
    {

    }

    Car * fix()
    {

    }
protected:
private:
};

class Car
{
public:
protected:
private:
};

//关联(实线) 关联 张三 有车 一个类 是 另外一个类的成员变量
class AdvZhanSan
{
public:
    void GoWork()
    {
        //m_car->
    }
protected:
private:
    Car *m_car;
    //Car m_car2;
};
int main()
{

    cout<<"hello..."<<endl;

    return 0;
}