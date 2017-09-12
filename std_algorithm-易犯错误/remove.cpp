#include <iostream>     // std::cout
#include <algorithm>    // std::unique, std::distance
#include <vector>       // std::vector
#include <string>
using namespace std;
 


void test1()
{
    vector<int> array;  
    array.push_back(1);  
    array.push_back(6);  
    array.push_back(3);  
    array.push_back(6);  
    array.push_back(6);  
    array.push_back(2);  

    for( int i:array)
        cout<<i<<" ";
    cout<<endl;

    auto itremove=remove(array.begin(), array.end(),6);//返回迭代器.
    for( int i:array)
        cout<<i<<" ";
    cout <<": 少了6,多了2 "<<endl;
/*
 注：
 remove是个stl的通用算法std::remove(first,last,val).
 移除[first, last)范围内等于val的元素
 但这个函数只是把val移到vec的末尾，并不真正删除.
 真正删除还是要调用一次erase函数
 
*/
    array.erase(itremove,array.end());
    for( int i:array)
        cout<<i<<" ";
    cout<<endl;    
/*
也可以使用remove方法：
array.erase( remove(array.begin(), array.end(),6),  array.end() ); 
*/
}


void test2()
{
    vector<int> array;  
    array.push_back(1);  
    array.push_back(6);  
    array.push_back(3);  
    array.push_back(6);  
    array.push_back(6);  
    array.push_back(2);  

    for( int i:array)
        cout<<i<<" ";
    cout<<endl;

    auto itremove=remove(array.begin(), array.begin()+5,6);//返回迭代器.
    for( int i:array)
        cout<<i<<" ";
    cout<<" :少了6,但是却多了3.."<<endl;

    array.erase(itremove,array.end());
    for( int i:array)
        cout<<i<<" ";
    cout<<endl;    

   // cout<<" 修改见test3:"<<endl;
 
}

void test3()
{
    vector<int> array;  
    array.push_back(1);  
    array.push_back(6);  
    array.push_back(3);  
    array.push_back(6);  
    array.push_back(6);  
    array.push_back(2);  

    for( int i:array)
        cout<<i<<" ";
    cout<<endl;

    auto thelast=array.begin()+4;
    auto itremove=remove(array.begin(),thelast ,6);//返回迭代器.
    for( int i:array)
        cout<<i<<" ";
    cout<<" :少了6,但是却多了3.."<<endl;

 /*   array.erase(itremove,array.end());
    for( int i:array)
        cout<<i<<" ";
    cout<<endl;   */ 

    string  s="修改: remove只保证:\n\
    1)返回的迭代器iter到给定区间的begin之间的值是!=value的.\n\
    2)iter到给定的last区间的值是应该全部==value的,\n\
    3) 所以删除器erase()区间应该为iter到给定的last.";

    cout<<s<<endl;

 
    array.erase(itremove,thelast);
    for( int i:array)
        cout<<i<<" ";//保留了最后一个6
    cout<<endl;   

}

/*
Removing is done by shifting (by means of move assignment) the elements in the range in such a way that the elements that are not to be removed appear in the beginning of the range. Relative order of the elements that remain is preserved and the physical size of the container is unchanged. Iterators pointing to an element between the new logical end and the physical end of the range are still dereferenceable, but the elements themselves have unspecified values (as per MoveAssignable post-condition). A call to remove is typically followed by a call to a container's erase method, which erases the unspecified values and reduces the physical size of the container to match its new logical size.
*/


 int main(int argc, char const *argv[])

{
    
    test1();
    cout<<"--\n";
    test2();
    test3();
    //getchar();  
    return 0;  
}

//g++ l349.cpp  -std=c++11 -w


/*
stl的实现:

无谓词的版本
template< class ForwardIt, class T >
ForwardIt remove(ForwardIt first, ForwardIt last, const T& value)
{
    first = std::find(first, last, value);
    if (first != last)
        for(ForwardIt i = first; ++i != last; )
            if (!(*i == value))
                *first++ = std::move(*i);
//把后面的不等于value的元素移到前面.返回的是完成移动的first
    return first;
}


有谓词:
template<class ForwardIt, class UnaryPredicate>
ForwardIt remove_if(ForwardIt first, ForwardIt last, UnaryPredicate p)
{
    first = std::find_if(first, last, p);
    if (first != last)
        for(ForwardIt i = first; ++i != last; )
            if (!p(*i))
                *first++ = std::move(*i);
    return first;
}
*/