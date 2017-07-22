
#include<iostream>  
#include <vector>  
using namespace std;  
  
class A {  
public:  
    A (int i = 0) : m_i (i) {  
        cout << "无参构造：" << this << endl;  
    }  
    A (const A& that) : m_i (that.m_i) {  
        cout << "拷贝构造：" << &that << "->" << this  
            << endl;  
    }  
    A& operator= (const A& that) {  
        cout << "拷贝赋值：" << &that << "->" << this  
            << endl;  
        if (&that != this)  
            m_i = that.m_i;  
        return *this;  
    }  
    ~A (void) {  
        cout << "析构函数：" << this << endl;  
    }  
private:  
    int m_i;  
};  
int main (void) {  
  
    vector<A> va (3);  
    return 0;  
    }