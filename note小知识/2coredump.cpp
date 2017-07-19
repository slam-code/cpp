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
            return foo();
    }
