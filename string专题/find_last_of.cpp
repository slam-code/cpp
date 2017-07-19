
#include <iostream>
#include <string>

int main ()
{
  std::string str ("PLease, replace the vowels in this sentence by asterisks.");
  std::string::size_type found = str.find_first_of("aeiou");//任意一个字符匹配即返回。
  while (found!=std::string::npos)
  {
    str[found]='*';
    found=str.find_first_of("aeiou",found+1);
  }

  std::cout << str << '\n';

  return 0;
}

//Pl**s*, r*pl*c* th* v*w*ls *n th*s s*nt*nc* by *st*r*sks.

  string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            i = s.find_first_of("aeiouAEIOU", i);//在s中，查找第一个与“aeiouAEIOU”的任意一个字符匹配的位置。从i开始.
            j = s.find_last_of("aeiouAEIOU", j);
            if (i < j) {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
 //hello -> holle 



 #include <algorithm>
#include <iostream>
#include <vector>
 
int main()
{
    std::vector<int> v{0, 2, 3, 25, 5};
    std::vector<int> t{3, 19, 10, 2};
 
    auto result = std::find_first_of(v.begin(), v.end(), t.begin(), t.end());
 
    if (result == v.end()) {
        std::cout << "no elements of v were equal to 3, 19, 10 or 2\n";
    } else {
        std::cout << "found a match at "
                  << std::distance(v.begin(), result) << "\n";
    }
 }

/*

Output:
found a match at 1

 */