

#ifndef EFFECTIVECPP_CH3_2_H
#define EFFECTIVECPP_CH3_2_H

#include <cstring>
#include "all.h"


class CTextBlockLength
{
public:
    size_t length() const;

private:
    char *pText;
    mutable size_t textLength;//成员变量可修改，即使在const函数内也是如此
    mutable bool LengthIsValid;
};

size_t CTextBlockLength::length() const
{
    if (!LengthIsValid)
    {
        textLength = strlen(pText);
        LengthIsValid = true;
    }
    return textLength;
}

//cast转型
class CTextBlock
{
public:
    CTextBlock(std::string s)
    {
        pText = &s[0];
    }

    const char &operator[](std::size_t position) const
    {
        std::cout << "\n调用const版本[]: ";
        return pText[position];
    }

    char &operator[](std::size_t position)
    {
        std::cout << "\nnon-const版本[]:调用 const版本以节约代码篇幅 ";
        return
                const_cast<char &>(static_cast<const CTextBlock &>(*this)[position]);//

    }

private:
    char *pText;
};

void f1()
{
    const CTextBlock cctb("hello");
    char *pc = (char *) &cctb[0]; //const[]赋值给non-const对象，丢失了const属性
    *pc = 'j';
    cout << pc;
}


int main()
{

    f1();

    return 0;
}


#endif //EFFECTIVECPP_CH3_2_H
