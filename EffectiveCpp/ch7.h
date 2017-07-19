//
// Created by shen on 16-9-15.
//

#ifndef EFFECTIVECPP_CH7_H
#define EFFECTIVECPP_CH7_H

#include "all.h"
/*
 * 析构函数声明为虚函数恐怕是面试中最常见的问题之一。
 * 目的在于以基类指针调用析构函数时能够正确地析构子类部分的内存。
 * 否则子类部分的内存将会泄漏，
 * 值得一提的是虚函数表指针的内存占用问题，我们知道所有存在虚方法的对象中都会存有一个虚函数表指针vptr，
 * 用来在运行时定位虚函数。同时，每个存在虚方法的类也会对应一个虚函数列表的指针vtbl。
 * 函数调用时会在vtbl指向的虚函数表中寻找vptr指向的那个函数。
 * */
namespace ch7 {
    class TimeKeeper {
    public:
        TimeKeeper() { cout << "time base\n"; };

        virtual ~TimeKeeper() { cout << " time析构\n"; }; //含有派生类，则析构函数一般为虚函数
    };

    class AtomiClock : public TimeKeeper {
    public:
        AtomiClock() { cout << "atom derived class \n"; }

        ~AtomiClock() { cout << "Atomi 析构\n"; }
    };//原子钟
    class WaterClock : public TimeKeeper {
    };//水钟
    class WristWatch : public TimeKeeper {
    };//腕表

    TimeKeeper *getTimeKeeper() {
        auto temp = new AtomiClock();
        return temp;
    };

    void f1() {

        TimeKeeper *ptk = getTimeKeeper();
        delete ptk;
    }

    class Point {
    public:
        Point(int xCoord, int yCoord);

        ~Point();

    private:
        int x, y;
    };
}
#endif //EFFECTIVECPP_CH7_H
