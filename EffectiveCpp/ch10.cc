
#include "all.h"

/*
 *
 * 令operator=()返回一个 *this,引用。
 * */



class Widget
{
public:
    Widget()
    { cout << "widget() \n"; }

    Widget &operator=(const Widget &rhs)
    {
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


}
int main()
{

    f();
    return 0;
}