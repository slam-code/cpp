#include <string>
#include <future>

struct X
{
    void foo(int,std::string const&);
    std::string bar(std::string const&);
};


X x;
//引用参数和非引用的区别：
auto f1=std::async(&X::foo,&x,42,"hello");//调用p->foo(42,"hello"),p是指向x的指针
auto f2=std::async(&X::bar,x,"goodbye");//调用temp.bar("googlebye"),temp是x的拷贝副本

struct Y
{
    double operator()(double);
};
Y y;
auto f3=std::async(Y(),3.141);//调用tempy(3.14),tempy通过y的移动构造函数得到。
auto f4=std::async(std::ref(y),2.718);//调用y(2.718)
X baz(X&);
auto f6=std::async(baz,std::ref(x));//调用baz(x)

//std::async()允许只能移动类型作为函数参数
class move_only
{
public:
    move_only();
    move_only(move_only&&);
    move_only(move_only const&) = delete;
    move_only& operator=(move_only&&);
    move_only& operator=(move_only const&) = delete;
    void operator()();
};
auto f5=std::async(move_only());//调用temp(),temp是通过std::move(move_only())构造得到。
