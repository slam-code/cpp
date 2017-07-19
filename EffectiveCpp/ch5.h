//
// Created by shen on 16-9-15.
//

#ifndef EFFECTIVECPP_CH5_H
#define EFFECTIVECPP_CH5_H

#include "all.h"
namespace  ch5{

    template <typename T>
    class NameObject{
    public:
        NameObject(string& name,const T& value):nameValue(name),objectValue(value){};

    private:
        string& nameValue;
        const T objectValue;
    };

    void f1()
    {
        string newDog("pers");
        string oldDog("sath");
        NameObject<int>p(newDog,2);
        NameObject<int>s(oldDog,36);
       // p=s;//copy assignment 非法操作,引用一经初始化不可改变

    }
}
#endif //EFFECTIVECPP_CH5_H
