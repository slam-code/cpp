#include <fstream>
#include <string.h>
using namespace std;
#include <stdlib.h>
#include <iostream>

/*
随机访问二进制数据文件

一般情况下读写是顺序进行的,即逐个字节进行读写。但是对于二进制数据文件来说,可以利用上面的成员函数移动指针,随机地访问文件中任一位置上的数据,还可以修改文件中的内容。

[例13.16] 有个学生的数据,要求:
把它们存到磁盘文件中;
将磁盘文件中的第,3,5个学生数据读入程序,并显示出来;
将第个学生的数据修改后存回磁盘文件中的原有位置。
从磁盘文件读入修改后的个学生的数据并显示出来。

要实现以上要求,需要解决个问题：
由于同一磁盘文件在程序中需要频繁地进行输入和输出，因此可将文件的工作方式指定为输入输出文件，即ios::in|ios::out|ios::binary。
正确计算好每次访问时指针的定位，即正确使用seekg或seekp函数。
正确进行文件中数据的重写(更新)。

*/
struct student
{
   int num;
   char name[20];
   float score;
};
int main( )
{
   student stud[5]={1001,"Li",85,1002,"Fun",97.5,1004,"Wang",54,1006,"Tan",76.5,1010,"ling",96};
   fstream iofile("stud.dat",ios::in|ios::out|ios::binary);
   //用fstream类定义输入输出二进制文件流对象iofile
   if(!iofile)
   {
      cerr<<"open error!"<<endl;
      abort( );
   }
   for(int i=0;i<5;i++)  //向磁盘文件输出个学生的数据
      iofile.write((char *)&stud[i],sizeof(stud[i]));
   student stud1[5];  //用来存放从磁盘文件读入的数据
   for(int i=0;i<5;i=i+2)
   {
      iofile.seekg(i*sizeof(stud[i]),ios::beg);  //定位于第,2,4学生数据开头
      //先后读入个学生的数据,存放在stud1[0],stud[1]和stud[2]中
      iofile.read((char *)&stud1[i/2],sizeof(stud1[0]));
      //输出stud1[0],stud[1]和stud[2]各成员的值
      cout<<stud1[i/2].num<<" "<<stud1[i/2].name<<" "<<stud1[i/2].score<<endl;
   }
   cout<<endl;
   stud[2].num=1012;  //修改第个学生(序号为)的数据
   strcpy(stud[2].name,"Wu");
   stud[2].score=60;
   iofile.seekp(2*sizeof(stud[0]),ios::beg);  //定位于第个学生数据的开头
   iofile.write((char *)&stud[2],sizeof(stud[2]));  //更新第个学生数据
   iofile.seekg(0,ios::beg);  //重新定位于文件开头
   for(int i=0;i<5;i++)
   {
      iofile.read((char *)&stud[i],sizeof(stud[i]));  //读入个学生的数据
      cout<<stud[i].num<<" "<<stud[i].name<<" "<<stud[i].score<<endl;
   }
   iofile.close( );
   return 0;
}
