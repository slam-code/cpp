//#include "stdafx.h"
//http://www.cnblogs.com/milanleon/p/5892420.html
#include "iostream"
using std::cout;
using std::endl;

#include "boost/any.hpp"
#include "boost/assert.hpp"
using namespace boost;

//判断any内部元素的类型
template <typename T> bool match_type(any& a)
{
    if (a.empty())
        return false;

    return typeid(T) == a.type();
}

//获得any内部值
template<typename T> T get_value(any& a)
{
    BOOST_ASSERT(match_type<T>(a));

    return any_cast<T>(a);
}

//获得any内部值的指针
template <typename T> T* get_pointer(any& a)
{
    BOOST_ASSERT(match_type<T>(a));

    return any_cast<T>(&a);
}

//获得any内部值的引用（引用可以被当做左值来使用）
template <typename T> T& get_reference(any& a)
{
    BOOST_ASSERT(match_type<T>(a));
    
    return any_cast<int&>(a);//获得a内部值的引用
    //return *any_cast<T>(&a);//*运算获得的是变量的引用，所以可以当做左值来使用
}

int main()
{
    any a = 10;

    int iNum = get_value<int>(a);//获得a的内部元素
    cout << iNum << endl;

    int * p = get_pointer<int>(a);//获得a内部元素的指针
    cout << *p << endl;

    get_reference<int>(a) = 5;//获得a内部元素引用，引用可以被当做左值来使用
    cout << *p << endl;

    if (match_type<int>(a))//判断a内部元素类型是否为int
        cout << "true" << endl;
    
    return 0;
}