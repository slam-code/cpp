#include <iostream>
#include <vector>

using namespace std;

class obj
{
public :
    obj()
    { cout << ">> create obj " << endl; }

    obj(const obj &other)
    { cout << ">> copy create obj " << endl; }

    ~obj()
    { cout << " 析构.." << endl; }
};

vector<obj> foo()
{
    vector<obj> c;
    c.push_back(obj()); //创建一次，然后拷贝一次

    cout << "---- exit foo ----" << endl;
    return c;//可能拷贝，可能不拷贝
}

int main()
{
    vector<obj> k;
    k = foo();//编译时，-std=c++11，则会减少１次拷贝
}
/*
在老版本中,foo()函数返回一个临时对象（这里用~tmp来标识它）
执行vector的 ‘=’ 函数，将对象k中的现有成员删除，将~tmp的成员复制到k中来
删除临时对象~tmp

在C++11的版本中，foo()函数返回一个临时对象（这里用~tmp来标识它）
执行vector的 ‘=’ 函数，将对象k中的成员与~tmp的成员互换，此时k中的成员就被替换成了~tmp中的成员。
删除临时对象~tmp（此时就删除了以前的k中的成员）
关键的过程就是第2步，它不是复制而是交换，从而避免的成员的拷贝，但效果却是一样的。
不用修改代码，性能却得到了提升，对于程序员来说就是一份免费的午餐。
但是，这份免费的午餐也不是无条件就可以获取的，需要带上-std=c++11编译，
如果使用STL代码可以享用这份午餐.
*/