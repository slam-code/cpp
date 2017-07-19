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
	for (;it != v1.end(); it++) {  
		if (*it % 2 == 1) {  
			v1.erase(it++);  //v1.erase(it)之后，it及其后面的迭代器已经失效，不应该再使用这些迭代器。再执行it++，其行为是未定义的。
		}  

		v1.shrink_to_fit();

	}

	v1.shrink_to_fit();

	for(auto it:v1)
		cout<<it<<" ";
	cout<<endl;




	return 0;
}