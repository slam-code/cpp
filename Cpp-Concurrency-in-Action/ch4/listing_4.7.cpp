#include <string>
#include <future>
#include <iostream>

struct X {
    void foo(int, std::string const &) {};

    std::string bar(std::string const &) { return "ok"; };
};

/*	std::async允许你通过添加额外的调用参数,向函数传递额外的参数。
 * 当第一个参数是一个指向成员函数的指针,第二个参数提供有这个函数成员类的具体对象
 * (不是直接的,就是通过指针,还可以包装在std::ref中),剩余的参数可作为成员函数的参数传入。
 * 否则,第二个和随后的参数将作为函数的参数,或作为指定可调用对象的第一个参数。
 *
 * 与std::thread一样,当std::async的参数为右值(rvalues)时,拷贝操作将使用移动的方式转移原始数据。
 * 这就允许使用“只移动”类型作为函数对象和参数。*/

X x;
//引用参数和非引用的区别：
auto f1 = std::async(&X::foo, &x, 42, "hello");//调用p->foo(42,"hello"),p是指向x的指针
auto f2 = std::async(&X::bar, x, "goodbye");//调用temp.bar("googlebye"),temp是x的拷贝副本，而不是x本身。

struct Y {
    double operator()(double) {
        return 0.0;
    };
};

Y y;
///使用std::async向函数传递参数
auto f3 = std::async(Y(), 3.141);//调用tempy(3.14),tempy通过y的移动构造函数得到。
auto f4 = std::async(std::ref(y), 2.718);//调用y(2.718)
X baz(X &) {
    X tempx;
    return tempx;
};

auto f6 = std::async(baz, std::ref(x));//调用baz(x)

//std::async()允许只可移动类型作为函数参数
class move_only {
public:
    move_only() {};

    move_only(move_only &&) {};

    move_only(move_only const &) = delete;

    move_only &operator=(move_only &&);

    move_only &operator=(move_only const &) = delete;

    void operator()() {};
};

/*可以在函数调用之前,向 std::async传递一个额外参数。这个参数类型是std::launch。
 *
 * std::launch::defered,　用来表明函数调用被延迟到wait()或get()函数调用时才执行,
 * std::launch::async　　表明函数必须在其所在的独立线程上执行,
 * std::launch::deferred | std::launch::async 表明实现可以选择这两种方式的一种。
*/

int main() {
    auto f5 = std::async(move_only());//调用temp(),temp是通过std::move(move_only())构造得到。
    auto f6 = std::async(std::launch::async, Y(), 1.2); //立即在新线程上执行
    auto f7 = std::async(std::launch::deferred, baz, std::ref(x));//延迟执行:在调用wait()或get()调用时执行
    auto f8 = std::async(
            std::launch::deferred | std::launch::async,
            baz, std::ref(x));//cpu任意选择执行方式
    auto f9 = std::async(baz, std::ref(x));
    f7.wait();//调用延迟函数
    std::cout << "main done...\n";
}

//clang++ listing_4.7.cpp -std=c++11 -lpthread