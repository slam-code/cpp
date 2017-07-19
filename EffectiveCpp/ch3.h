#ifndef EFFECTIVECPP_CH3_H
#define EFFECTIVECPP_CH3_H

#include "all.h"

namespace ch3 {
    class Widget2;

    char greeting[] = "sdy";
    char *p = greeting;
    const char *pp = greeting;
    char *const ppp = greeting;
    const char *const pppp = greeting;

    void f0(const Widget2 *pw); //2种方式作用相同。等价
    void f1(Widget2 const *pw);

    void f2() {
        std::vector<int> vec;
        const std::vector<int>::iterator iter = vec.begin();
        *iter = 10;  //ok,改变iter指向的内容
        // ++iter;//错误，iter 是const

        std::vector<int>::const_iterator citer = vec.begin();
        //*citer=10; //错误，citer指向的是const对象
        ++citer;     //ok ，citer本身不是const
    }


    class Rational {
    };

    const Rational operator*(const Rational &hls, const Rational &rhs);//返回const对象


    //p19
    class TextBlock {
    public:
        TextBlock(std::string s) {
            text = s;
        }

        const char &operator[](std::size_t position) const {
            std::cout << "\n调用const版本[]: ";
            return text[position];
        }

        char &operator[](std::size_t position) {
            std::cout << "\n调用non-const版本[]: ";
            return text[position];
        }

    private:
        std::string text;
    };

    void f3() {
        TextBlock tb("hello");
        std::cout << tb[0]; //重载了[]运算符

        const TextBlock ctb(" world"); //调用const版本
        std::cout << ctb[1];
    }

    void f4(const TextBlock &ctb) {
//        ctb[0]='y'; //错误，ctb[0]返回const对象，故不能修改

        std::cout<< ctb[0]<<ctb[1]<<ctb[2];

    };

    void f5(TextBlock &tb) {
        tb[0] = 'Z'; //正确，tb[0]返回非const对象，string[0]可修改！
        //std::cout << std::endl<<tb[0]<<std::endl<<tb[1]<<std::endl<<tb[2];
        std::cout<<tb[0]<<tb[1]<<tb[2]<<std::endl;
        printf("%c ,%c ,",tb[0],tb[1]);
        printf("%c ,%c ,",tb[2],tb[3]);
    }

    // const转型


}

#endif


