//
// Created by shen on 16-9-15.
//

#ifndef EFFECTIVECPP_CH10_H
#define EFFECTIVECPP_CH10_H

#include "all.h"

namespace ch10 {

    void f() {
        int x, y, z;
        x = y = z = 15;//等价
        x = (y = (x = 15));
        //=操作符返回指向左侧的引用reference
    }

    class Widget{
    public:
        Widget(){cout<<"widget() \n";}
        Widget&operator=(const Widget& rhs){
            cout<<"= copy \n";
            return * this;
        }
    };
}
#endif //EFFECTIVECPP_CH10_H
