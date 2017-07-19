//https://www.zhihu.com/question/20184857/answer/94210921


#include <iostream>

class Rational{
public:
    Rational();
    Rational(int x);
    Rational(int x, int y);
    Rational(const Rational& r);
    const Rational& operator=(int x);
    const Rational& operator=(const Rational& r);
    virtual ~Rational();

    bool operator== (const Rational& other) const;

    friend const Rational operator+ (const Rational& r1, 
                                     const Rational& r2);
    friend const Rational operator- (const Rational& r1, 
                                     const Rational& r2);
    friend const Rational operator* (const Rational& r1, 
                                     const Rational& r2);
    friend const Rational operator/ (const Rational& r1, 
                                     const Rational& r2);
    friend std::ostream& operator<< (std::ostream&, const Rational& r);
    friend std::istream& operator>> (std::istream&, Rational& r);
private:
    static int gcd(int p, int q);
    int num; //numerator
    int div; //divisor
};

int main(int argc, char* argv[])
{
    Rational a(1, 3); //a等于三分之一
    Rational b = 3; //b等于3，3也是有理数
    b = a;
    Rational c(a+b+Rational(1,3)); //有理数可以做加法
    std::cout << "a=" << a << std::endl;
    std::cout << "b=" << b << std::endl;
    std::cout << "c=" << c << std::endl; //输出结果

    std::cout << "Please input a Rational number like 13/15" << std::endl;
    Rational d;
    std::cin >> d;
    std::cout << "value d+1=" << d+1 << std::endl;
    return 0;
}

//gcc -g -O0 -o rational Rational.cpp -lstdc++