1.   int sprintf( char *buffer, const char *format [, argument] ... );
      <stdio.h>
例如：
      int ss;
      char temp[64];
      string str;
      ss = 1000;
      sprintf(temp, "%d", ss);
      string s(temp);
       //调用string的方法
      cout<<s.c_str()<<endl;//1000
      cout<<s.size()<<endl;  //长度为4

2.char *_itoa( int value, char *string, int radix );
        <stdlib.h>
  例如：
      char buffer[20];
      int  i = 3445;   
     _itoa( i, buffer, 10 );
      string s(buffer);


3. stringstream( )
     <sstream.h>
 例如：
       int hello=4;
       stringstream ss;
       ss<<hello;
       string   s=ss.str();
     //调用string的方法
       cout<<s.c_str()<<endl;





C++本身就提供了字符串与整型数之间的互换，那就是利用stringstream。下面是使用方法：
核心： 利用C++中的stringstream流。 
由于使用过程比较简单就不再赘述，直接给出示例，重要的地方在示例注释中给予说明。 

完整示例： 
#include <iostream> 
#include <string> 
#include <sstream>      //要使用stringstream流应包含此头文件 
using namespace std; 

int main() 
{ 
stringstream stream;     //声明一个stringstream变量 
int n; 
string str; 

//string转int 
stream << "1234";     //向stream中插入字符串"1234" 
stream >> n;     //从stream中提取刚插入的字符串"1234"  并将其赋予变量n完成字符串到int的转换 
cout << n << endl;     //输出n 

stream.clear();     //同一stream进行多次转换应调用成员函数clear 

//int转string 
stream << 1234;     //向stream中插入整型数1234 
stream >> str;     //从steam中提取刚插入的整型数   并将其赋予变量str完成整型数到string的转换 
cout << str << endl;     //输出str 
return 0; 
} 

上面方法很简便, 缺点是处理大量数据转换速度较慢..
C library中的sprintf, sscanf 相对更快

可以用sprintf函数将数字输出到一个字符缓冲区中. 从而进行了转换...
例如：
已知从0点开始的秒数(seconds) ，计算出字符串"H:M:S",  其中H是小时, M＝分钟，S＝秒

         int H, M, S;
        string time_str;
        H=seconds/3600;
        M=(seconds%3600)/60;
        S=(seconds%3600)%60;
        char ctime[10];
        sprintf(ctime, "%d:%d:%d", H, M, S);             // 将整数转换成字符串
        time_str=ctime;                                                 // 结果 


与sprintf对应的是sscanf函数, 可以将字符串转换成数字

    char    str[] = "15.455";
    int     i;
    float     fp;
    sscanf( str, "%d", &i );         // 将字符串转换成整数   i = 15
    sscanf( str, "%f", &fp );      // 将字符串转换成浮点数 fp = 15.455000
    //打印
    printf( "Integer: = %d ",  i+1 );
    printf( "Real: = %f ",  fp+1 ); 
    return 0;




    从INT 到STRING的几种方法

1.   int sprintf( char *buffer, const char *format [, argument] ... );
      <stdio.h>
例如：
      int ss;
      char temp[64];
      string str;
      ss = 1000;
      sprintf(temp, "%d", ss);
      string s(temp);
       //调用string的方法
      cout<<s.c_str()<<endl;//1000
      cout<<s.size()<<endl;  //长度为4

2.char *_itoa( int value, char *string, int radix );
        <stdlib.h>
  例如：
      char buffer[20];
      int  i = 3445;   
     _itoa( i, buffer, 10 );
      string s(buffer);


3. stringstream( )
     <sstream.h>
 例如：
       int hello=4;
       stringstream ss;
       ss<<hello;
       string   s=ss.str();
     //调用string的方法
       cout<<s.c_str()<<endl;


如果库中其他的函数可以作到，不妨共享

