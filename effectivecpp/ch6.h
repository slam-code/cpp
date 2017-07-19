//
// Created by shen on 16-9-15.
//

#ifndef EFFECTIVECPP_CH6_H
#define EFFECTIVECPP_CH6_H

#include "all.h"
namespace  ch6{
    class Home{
    public:

    private:
        Home(const Home &); //声明为private，切不实现，则等效于删除该函数
        Home&operator=(const Home);
    };

    //基类
    class Uncopyable {
    protected:
        Uncopyable(){}
        ~Uncopyable(){}

    private:
        Uncopyable(const Uncopyable&);
        Uncopyable&operator=(const Uncopyable&);
    };
    //派生类
    class Homes:private Uncopyable{
        //无法调用copy和 =了
    };

}
#endif //EFFECTIVECPP_CH6_H
