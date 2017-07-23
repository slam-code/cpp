#include<functional>
#include<iostream>
//http://blog.csdn.net/qq575787460/article/details/8531397
using namespace std;

class View{

public:
void onClick(int x, int y)
{
cout<<"X : "<<x<<", Y : "<<y<<endl;
}
} ;

// 定义function类型的变量：clickCallback , 三个参数
function<void (View*, int, int)> clickCallback ;

//
int main(int argc, const char * argv[])
{
View button ;
// 指向成员函数
clickCallback = &View::onClick ;
// 进行调用
clickCallback(&button, 10, 123);
return 0;
}
