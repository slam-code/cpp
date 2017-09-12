#include <iostream>     // std::cout
#include <algorithm>    // std::unique, std::distance
#include <vector>       // std::vector
using namespace std;

/*
ector::erase()：从指定容器删除指定位置的元素或某段范围内的元素
vector::erase()方法有两种重载形式
如下：
iterator erase(   iterator _Where);
iterator erase(   iterator _First,   iterator _Last);
如果是删除指定位置的元素时：
返回值是一个迭代器，指向删除元素下一个元素;
如果是删除某范围内的元素时：返回值也表示一个迭代器，指向最后一个删除元素的下一个元素;

*/


void test1()
{
    vector<int> array;  
    array.push_back(1);  
    array.push_back(6);  
    array.push_back(3);  
    array.push_back(6);  
    array.push_back(6);  
    array.push_back(2);  
  
    vector<int>::iterator itor;  
    vector<int>::iterator itor2;  
    for(itor=array.begin();itor!=array.end();)  
    {  
        if(6==*itor)  
        {  
           itor2=itor;  
           itor=array.erase(itor2);  
  
        }  
        itor++;  
    }  
    itor=array.begin();  
    for(itor=array.begin();itor!=array.end();)  
    {  
        cout<<(*itor++)<<" ";  
    }  
    cout<<endl;
/*
运行结果输出1362，可见其中一个6并未删除，这是迭代器的问题。
原因在于erase以后，itor已经指向下一个元素了，不应该再使用itor++，
否则会跳过下一个元素，即连续两个6时跳过了第二个6. 
另外，在itor2=itor时，两个itor是一样的，这样做并无意义。

可修改如下：
vector<int>::iterator itor;    
for(itor=array.begin();itor!=array.end();)  
{  
    if(6==*itor)  
    {   
        itor=array.erase(itor);  
    }  
    else  
    {  
        itor++;  
    }  
} 

或者:
vector<int>::iterator itor;  
for(itor=array.begin();itor!=array.end();itor++)  
{  
    if(6==*itor)  
    {  
        itor=array.erase(itor);  
        itor--;  
    }  
}  

也可以使用remove方法：
array.erase( remove(array.begin(), array.end(),6),  array.end() ); 
*/
}


void test2()
{
    vector<int> veci;
    veci.push_back(1);
    veci.push_back(2);
    veci.push_back(3);
    veci.push_back(4);
    veci.push_back(5);
    veci.push_back(3);
    veci.push_back(2);
    veci.push_back(3);
    for(vector<int>::iterator iter=veci.begin(); iter!=veci.end(); iter++)
    {
          if( *iter == 3)
                 veci.erase(iter);
    }

/*
1,当veci.erase(iter)之后，iter就变成了一个野指针，对一个野指针进行 iter++ 是肯定会出错的。

2,查看MSDN，对于erase的返回值是这样描述的：
    An iterator that designates the first element remaining beyond any elements removed, 
    or a pointer to the end of the vector if no such element exists，于是改代码：
    for(vector<int>::iterator iter=veci.begin(); iter!=veci.end(); iter++)
    {
          if( *iter == 3)
                 iter = veci.erase(iter);
    }
    这段代码也是错误的：1）无法删除两个连续的"3"； 2）当3位于vector最后位置的时候，
    也会出错（在veci.end()上执行 ++ 操作）
3,正确的代码应该为：
    for(vector<int>::iterator iter=veci.begin(); iter!=veci.end(); )
    {
         if( *iter == 3)
              iter = veci.erase(iter);
          else
                iter ++ ;
    }
     
    为了避免对野指针进行操作，另一种解决方法如下：
    vector<int>::iterator itor2;
    for(vector<int>::iterator iter=veci.begin(); iter!=veci.end(); )
    {
         if( *iter == 3)
         {   
               itor2=iter;
              veci.erase(itor2);
         }
          else
                iter ++ ;
    }

4,要解决无法删除两个连续的3的另一种方法如下：
vector<int>  veci;
veci.erase(remove(veci.begin(),veci.end(),6),veci.end());
这里用到了remove（）函数，
注：remove是个stl的通用算法std::remove(first,last,val)移除[first, last)范围内等于val的元素
在vector里面用就类似于iter = std::remove(vec.begin(), vec.end(), val)

注意:
但这个函数只是把val移到vec的末尾，并不真正删除真正删除还是要调用一次erase函数
*/

}


 int main(int argc, char const *argv[])

{
    
    test1();
    //getchar();  
    return 0;  
}

//g++ l349.cpp  -std=c++11 -w