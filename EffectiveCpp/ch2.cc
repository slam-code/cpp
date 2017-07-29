
#ifndef EFFECTIVECPP_CH2_H
#define EFFECTIVECPP_CH2_H

#include <string>

//尽量以const，inline，enum代替define
namespace ch2
{
#define  ASPECT 1.653;
    const double appect = 1.654;
    const char *const author = "CH2";
    const std::string author2("CH2-2");

    class GamePlayer
    {
    private:
        static const int numTurns = 5; //常量声明式,类内初始值
        int scores[numTurns];
    };

// inline 代替 define
#define callWithMa(a, b) f((a)>(b)?(a):(b))

    template<typename T>
    inline void callWithMax(const T &a, const T &b)
    {
        f(a > b ? a : b);

    }
}
#endif


