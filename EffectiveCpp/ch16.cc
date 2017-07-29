
#include <string>
#include "all.h"

typedef std::string AddressLines[4]; //不好的写法，应该避免 AddressLines是string 数组

/*
 * 配对new 和delete
 * 配对new [] 和delete []
 *
 * */

class Wedgit
{
public:

    Wedgit()
    {
        sout("Wedgit ");
    }

    ~Wedgit()
    {
        sout("~Wedgit() ");
    }
};

void f16()
{
    std::string *stringArray = new std::string[10];
    delete stringArray;//只删除了一个对象，剩余9个。运行时，程序崩溃

    std::string *stringArray2 = new std::string[10];
    delete[] stringArray2;//删除了全部

    std::string *pal = new AddressLines;

    // auto pal=new AddressLines;

    delete[] pal;//必须是[]

}

void f17()
{
    Wedgit *w5 = new Wedgit[5];
    //delete(w5);

    delete[] w5;

}

int main()
{
    f17();

    //f16();
    return 0;
}