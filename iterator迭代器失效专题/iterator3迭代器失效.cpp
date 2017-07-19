#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	std::vector<int>  v1;  
	for (int i = 0; i <= 20; ++i) {  
		v1.push_back(i);  
	}  

	auto v2=v1;
	
	std::vector<int>::iterator it = v1.begin();  
	for (;it != v1.end(); ) {  
		if (*it % 2 == 1) {  
			v1.erase(it++);  //v1.erase(it)之后，it及其后面的迭代器已经失效，不应该再使用这些迭代器。再执行it++，其行为是未定义的。
		}  

		else 
			it++;
		v1.shrink_to_fit();

	}

	//v1.shrink_to_fit();

	for(auto it:v1)
		cout<<it<<" ";
	cout<<endl;




	return 0;
}



/*
list,set,map容器：
正确写法一：

std::list< int> List;
std::list< int>::iterator itList;
for( itList = List.begin(); itList != List.end(); )
{
      if( WillDelete( *itList) )
      {
            itList = List.erase( itList);
       }
       else
            itList++;
}

正确写法二：
　
std::list< int> List;
std::list< int>::iterator itList;
for( itList = List.begin(); itList != List.end(); )
{
      if( WillDelete( *itList) )
      {
          List.erase( itList++);
      }
      else
          itList++;
}

错误写法一：

std::list< int> List;
std::list< int>::iterator itList;
for( itList = List.begin(); itList != List.end(); itList++)
{
     if( WillDelete( *itList) )
     {
          List.erase( itList);
     }
}
错误写法二：

std::list< int> List;
std::list< int>::iterator itList;
for( itList = List.begin(); itList != List.end(); )
{
     if( WillDelete( *itList) )
     {
          itList = List.erase( ++itList);
      }
      else
          itList++;
}


1.5 分析

正确使用方法1：通过erase方法的返回值来获取下一个元素的位置
正确使用方法2：在调用erase方法之前先使用 “++”来获取下一个元素的位置
错误使用方法1：在调用erase方法之后使用“++”来获取下一个元素的位置，由于在调用erase方法以后，该元素的位置已经被删除，如果在根据这个旧的位置来获取下一个位置，则会出现异常。
错误使用方法2：同上
*/



/*



*/