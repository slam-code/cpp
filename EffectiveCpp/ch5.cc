

#include <all.h>
/*
 * 了解c++ 默认编写并调用哪些函数。
 * */
template<typename T>
class NameObject
{
public:
    NameObject(string &name, const T &value) : nameValue(name), objectValue(value)
    {};

private:
    string &nameValue;
    const T objectValue;
};

void f1()
{
    string newDog("pers");
    string oldDog("sath");
    NameObject<int> p(newDog, 2);
    NameObject<int> s(oldDog, 36);
    // p=s;//copy assignment 非法操作,引用一经初始化不可改变

}

int main()
{


    f1();
    return 0;
}