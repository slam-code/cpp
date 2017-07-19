#include <fstream>
using namespace std;
#include <iostream>
#include<string>
struct student
{
  char name[20];
   int num;
   int age;
   char sex;
};
int main( )
{
   student stud[3];
   int i;
   ifstream infile("stud.dat",ios::binary);
   if(!infile)
   {
      cerr<<"open error!"<<endl;
      return -1;
   }
   for(i=0;i<3;i++)
   infile.read((char*)&stud[i],sizeof(stud[i]));
   infile.close( );
   for(i=0;i<3;i++)
   {
      cout<<"NO."<<i+1<<endl;
      cout<<"name:"<<stud[i].name<<endl;
      cout<<"num:"<<stud[i].num<<endl;;
      cout<<"age:"<<stud[i].age<<endl;
      cout<<"sex:"<<stud[i].sex<<endl<<endl;
   }
   return 0;
}
/*

请思考，能否一次读入文件中的全部数据，如：
    infile.read((char*)&stud[0],sizeof(stud));
答案是可以的，将指定数目的字节读入内存，依次存放在以地址&tud[0]开始的存储空间中。要注意读入的数据的格式要与存放它的空间的格式匹配。由于磁盘文件中的数据是从内存中结构体数组元素得来的，因此它仍然保留结构体元素的数据格式。现在再读入内存，存放在同样的结构体数组中，这必然是匹配的。如果把它放到一个整型数组中，就不匹配了，会出错。
*/
