#include <iostream>     // std::cout
#include <algorithm>    // std::unique, std::distance
#include <vector>       // std::vector
using namespace std;
 
 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
void test0()
{
     
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(NULL);      //只会有warning,不会error
    //v.push_back(nullptr); //error ,push失败.nullptr是类型安全的.
    v.push_back(3);
    for (int i = 0; i < v.size(); ++i)
    {
        if(v[i]!=NULL)
            cout<<v[i]<<" ,";
        else
            cout<<" \nV含有NULL!!\n";
    }

}

void test1()
{
    TreeNode t0(0),t1(1),t2(2),t3(3),t4(4);
    vector<TreeNode*> v;

    v.push_back(&t0);
    v.push_back(&t1);
    v.push_back(NULL);
    for (int i = 0; i < v.size(); ++i)
    {
        if(v[i]!=NULL)
            cout<<v[i]->val<<" ,";
        else
            cout<<"V含有NULL!!\n";
    }

}
 int main(int argc, char const *argv[])
{
     test0();
     cout<<"\n---\n\n";
     test1();//push_back()是可以push null数据的.
    return 0;
}

//g++ l349.cpp  -std=c++11 -w