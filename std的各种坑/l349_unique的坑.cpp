#include <iostream>     // std::cout
#include <algorithm>    // std::unique, std::distance
#include <vector>       // std::vector
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(),nums1.end());
        std::sort(nums2.begin(),nums2.end());
        
        auto it1u=std::unique(nums1.begin(),nums1.end()); //实质上并没有删除元素,只是移动到后面.
        auto it2u=std::unique(nums2.begin(),nums2.end());
        nums1.resize( std::distance(nums1.begin(),it1u) );//必须手动删除

        nums2.resize( std::distance(nums2.begin(),it2u) );
        cout<<nums1.size()<<" "<<nums2.size()<<endl;
        for(auto it:nums1)
            cout<< it<<" ";
        
        cout<<"--\n";
        for(auto it:nums2)
            cout<< it<<" ";
   
        cout<<"**\n";
        auto it1=nums1.begin();
        auto it2=nums2.begin();
        vector<int> ans;
        while(it1!=nums1.end() && it2!=nums2.end())
        {
            if(*it1==*it2)
            {
                ans.push_back(*it1);
                it1++;
                it2++;
            }
            else if(*it1<*it2)
                it1++;
            else
                it2++;
            
        }
       unique(ans.begin(),ans.end());
       ans.shrink_to_fit();
       return ans;
    }
};

 int main(int argc, char const *argv[])
{
    
    Solution a;
    vector<int> n1{1,2,2,1};
     vector<int> n2{2,2};
    auto ans=a.intersection(n1,n2);
    for (int i = 0; i < ans.size(); ++i)
    {
        cout<<ans[i];
    }
    return 0;
}

//g++ l349.cpp  -std=c++11 -w