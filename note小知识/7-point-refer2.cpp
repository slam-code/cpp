#include <iostream>
#include <stdlib.h>
using namespace std;

/*class Log
{
    User operator;
};
*/

class Log
{
    int & oper;
public:
    void set(int & u)
    {
    	oper=u;
     }
    // Log():oper(0){ //传引用，类无法实例化　http://hgoldfish.com/blogs/article/19/

    // };
     Log(int i):oper(i)
     {

     }

};

int main(int argc, char const *argv[])
{
	int i=0;
	Log b(i);
	//b.set(2);右值

	return 0;
}