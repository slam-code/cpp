
/*
 * 用C++写一个有理数类，class Rational，实现基本的加减乘除和输入输出操作。
 * */
#include <iostream>

int main(int argc, char *argv[])
{
    Rational a(1, 3); //a等于三分之一
    Rational b = 3; //b等于3，3也是有理数
    b = a;
    Rational c(a + b + Rational(1, 3)); //有理数可以做加法
    std::cout << "a=" << a << std::endl;
    std::cout << "b=" << b << std::endl;
    std::cout << "c=" << c << std::endl; //输出结果

    std::cout << "Please input a Rational number like 13/15" << std::endl;
    Rational d;
    std::cin >> d;
    std::cout << "value d+1=" << d + 1 << std::endl;
    return 0;
}

//gcc -g -O0 -o rational Rational.cpp -lstdc++

//https://www.zhihu.com/question/20184857/answer/94210921
