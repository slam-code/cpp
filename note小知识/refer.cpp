#include <iostream>
#include <stdlib.h>
using namespace std;
#ifndef A
#define A int 
#endif
void func(A& x){
	if(&x==nullptr)
		cout<<"x==nullptr"<<endl;
	else 
		cout<<"func(x),x ="<<x<<endl;
};



int main(int argc, char const *argv[])
{
	A* a = NULL;
	cout << sizeof(*a) << endl;
	func(*a);

	int i=1;
	A* b = &i;
	func(*b);
	

	return 0;
}