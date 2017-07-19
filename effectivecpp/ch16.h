//
// Created by shen on 16-9-19.
//

#ifndef EFFECTIVECPP_CH16_H
#define EFFECTIVECPP_CH16_H

#include <string>

typedef std::string AddressLines[4]; //


void f16(){
    std::string* stringArray=new std::string[10];
    delete  stringArray;//只删除了一个对象，剩余9个。

    std::string* stringArray2=new std::string[10];
    delete [] stringArray2;//删除了全部

    std::string* pal=new AddressLines;

    delete[] pal;//必须是[]

}
#endif //EFFECTIVECPP_CH16_H
