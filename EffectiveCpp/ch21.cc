

#include <all.h>

/*
 * 必须返回对象时，就不能返回引用
 * */
class Rational{
public:
    Rational(int num=0,int den=1){};
private:
    int n,d;
    friend const Rational operator*(const Rational& lhs,const Rational &rhs);
};


/*

 const Rational& operator*(const Rational& lhs,const Rational& rhs){

    Rational result(lhs.n*rhs.n,lhs.d*rhs.d);//在stack上，引用所指的是局部对象，不能长久保存
    return result;

    Rational *result=new Rational(lhs.n*rhs.n,lhs.d*rhs.d);
    //heap上分配空间，但是调用者必须管理对象，有可能根本无法delete，造成资源泄漏
    return *result;

}

 */


const Rational operator*(const Rational& lhs,const Rational& rhs){

     return Rational(lhs.n*rhs.n,lhs.d*rhs.d);//必须返回对象时，就返回一个新对象。不要返回引用。

}

int main() {


    return 0;
}