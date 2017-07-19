#include <fstream>
using namespace std;
#include <iostream>

/*
对二进制文件的读写主要用istream类的成员函数read和write来实现。这两个成员函数的原型为
    istream& read(char *buffer,int len);
    ostream& write(const char * buffer,int len);
字符指针buffer指向内存中一段存储空间。len是读写的字节数。调用的方式为：
    a. write(p1,50);
    b. read(p2,30);
*/
struct student
{
   char name[20];
   int num;
   int age;
   char sex;
};
int main( )
{
   student stud[3]={"Li",1001,18,'f',"Fun",1002,19,'m',"Wang",1004,17,'f'};
   ofstream outfile("stud.dat",ios::binary);
   if(!outfile)
   {
      cerr<<"open error!"<<endl;
      return -1;//退出程序
   }
   for(int i=0;i<3;i++)
      outfile.write((char*)&stud[i],sizeof(stud[i]));
      outfile.close( );
/*
&stud[i] 是结构体数组第i个元素的首地址，但这是指向结构体的指针，与形参类型不匹配。因此 要用(char *)把它强制转换为字符指针。第2个参数是指定一次输出的字节数。sizeof (stud[i])的值是结构体数组的一个元素的字节数。调用一次write函数，就将从&tud[i]开始的结构体数组的一个元素输出到磁盘文件中，执行3次循环输出结构体数组的3个元素。
*/
   return 0;
}

/*
其实可以一次输出结构体数组的个元素，将for循环的两行改为以下一行：
   outfile.write((char*)&stud[0],sizeof(stud));
执行一次write函数即输出了结构体数组的全部数据。

可以看到，用这种方法一次可以输出一批数据，效率较高。在输出的数据之间不必加入空格，在一次输出之后也不必加回车换行符。在以后从该文件读入数据时不是靠空格作为数据的间隔，而是用字节数来控制。

*/
