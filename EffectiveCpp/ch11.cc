
#include "all.h"

/*
 *
 * 在operator=()中处理“自我赋值”
 * */



class Widget
{
public:
    Widget()
    { cout << "widget() \n"; }

    Widget &operator=(const Widget &rhs)
    {
        if(this==&rhs)
        {
            cout<<"selft = \n";
            return *this;
        }
        cout << "= copy \n";
        return *this;
    }
};

void f()
{
    int x, y, z;
    x = y = z = 15;//等价
    x = (y = (x = 15));
    //=操作符返回指向左侧的引用reference

    Widget w1,w2,w3;
    w1=(w2=w3);
    w1=w1;


}
int main()
{

    f();
    return 0;
}