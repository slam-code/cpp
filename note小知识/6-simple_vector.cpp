#include <iostream>
#include <vector>
#include <list>
using namespace std;
//http://blog.jobbole.com/108685/
class obj
{
    public :
    obj() { cout << ">> create obj " << endl; }
    obj(const obj& other) { cout << ">> copy create obj " << endl; }
    ~obj(){cout<< " 析构.."<<endl;}
};

    template <class T>
class container
{
public:
    T* value;

public:
    container() : value(NULL) {};
    ~container() { delete value; } 

    container(const container& other)
    {
        value = new T(*other.value);
    }

    // const container& operator = (container& other) //利用交换swap实现减少拷贝构造的原理
    // {
    //  T* tmp = value;
    //  value = other.value;
    //  other.value = tmp;
    //  return *this;
//    并没有写得很完善（一个典型的缺失就是在赋值函数中没有判断入参是否是本身），请不要将其应用于项目中。
    //     }//gcc期望的赋值函数的参数是const型的，而这里为了交换成员，而不能使用const型。


    container& operator = (container&& other) //移动赋值函数：
    {
       delete value;
       value = other.value;
       other.value = NULL;
       return *this;
   }

   container (container&& other) 
         //和移动赋值函数相应的，也有一个一个移动构造函数，也最好实现以下：
   {
    value = other.value;
    other.value = NULL;
}


        // const container& operator = (const container& other)
        // {
        //     delete value;
        //     value = new T(*other.value);
        //     return *this;
        // }

void push_back(const T& item)
{
    delete value;
    value = new T(item);
}
};

container<obj> foo()
{
    container<obj> c;
    c.push_back(std::move(obj()));//c.push_back(obj());

    cout << "---- exit foo ----" << endl;
    return c;
}

class bigobj
{
    public :
    bigobj() { cout << ">> create obj " << endl; }
    bigobj(const bigobj& other) { cout << ">> copy create obj " << endl; }
    bigobj(bigobj&& other) { cout << ">> move create obj " << endl; }
};

int main()
{
    container<obj> k ;
    k = foo();
    cout<<endl;

    list<bigobj> list;
        for(int i = 0; i < 3; i++)
        {
            bigobj obj;
            cout<<" - "<<endl;
            list.push_back(std::move(obj));// list.push_back(obj);
        }    
}
//http://blog.jobbole.com/105780/?utm_source=blog.jobbole.com&utm_medium=relatedPosts