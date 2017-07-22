

#include <iostream>

using namespace std;

/*
1字节(Byte）= 8位(bit)
linux内存的存储的最小单元是一个字节，对于多字节存储的方式一般采用低位优先
union让a,b,c 这三个字段共享一块内存区域，
64位,int为4字节, long为8字节，char为1字节
如果我们对b进行赋值0x12345678，那么在内存块中看到的是0x78 0x56 0x34 0x12，
在读取的时候a和b都为0x12345678，而读取c的时候，看到的是0x78.
*/
union {
    int a ;
    long b;
    unsigned char c;
} m;


int f2(){
    cout << sizeof(int) << endl;
    cout << sizeof(long) << endl;
    cout << sizeof(char) << endl<<"--\n";

    m.b = 0x12345678;
    cout << hex<<m.a <<endl;
    cout <<m.b <<endl;
    cout << m.c <<"  "<<(int)m.c <<endl;
    int a = 2220;
    cout << dec << a << endl;//还原输出流，以十进制的形式输出int
    return 0;
}


int GetEndianness()
{
    short s = 0x0110;
    char *p = (char *) &s;
    cout << s <<" ,"<<(int)p[0]<<" ,"<<(int)p[1]<< endl;
    if (p[0] == 0x10) //为何是2个数10:16进制，用2位表示
        return 0;// 小端格式,低位储存在前面。
    else if(p[0]==0x01)
        return 1;// 大端格式
    else
        runtime_error("p[0]");
}

int main()
{
    cout << GetEndianness()<<"---\n\n";
    //f2();
}

/*

网络字节序是大端，linux是小端
https://en.wikipedia.org/wiki/Endianness
http://www.cnblogs.com/fuchongjundream/p/3914770.html
http://www.cnblogs.com/freeliver54/archive/2011/09/23/2185808.html
http://www.cnblogs.com/cesc711/archive/2009/10/12/1581985.html

htobe64:那些函数（其实那些是宏定义），用来配置端口号是没有用的，因为已经有htons函数了。
但在解决TCP粘包问题中，这些函数就可以派上用场了。
解决TCP粘包问题的一个方法是，在每条消息的头部添加一个长度字段。
每一个主机在发送消息前，都把长度转换成大端字节序存放,(转换成小端字节序也行，只要CS两端统一即可)。
然后发送消息。对端在收到消息的长度字段后，就将其从大端字节序转换成主机字节序。
这里存在一个问题，怎么将收到的字节流转换成大端字节序的整型变量。答案是用memcpy函数。
在发送端将整型变量变成字节流也是用这个函数。



//发送端
int len = htobe32(a);//根据a得到长度
char ch[10];
memcpy(ch, &len, sizeof(len) );

//接收端
int len;
char* message;
memcpy(&len, message, sizeof(len) );//
a = be32toh(len);

*/