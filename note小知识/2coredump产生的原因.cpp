#include <stdio.h>;
#include <stdlib.h>;

int crash()
{
    char *xxx = "crash!!";
    xxx[1] = 'D'; // 写只读存储区!
    return 2;
}

int foo()
{
    return crash();
}

int main()
{
    foo();
    return 0;
}

//http://www.cnblogs.com/doctorqbw/archive/2011/12/21/2295962.html
//https://www.oschina.net/question/54100_30307