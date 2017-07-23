#include<algorithm>
#include<vector>
#include<functional>
#include<memory>
using namespace std;
struct X
{
    int x_;
    X(int x ):x_(x){printf("x =%d\n",x);}
    void f(){
printf("i=%d\n",x_);};
};

void g(std::vector<X> & v)
{
    std::for_each(v.begin(), v.end(), std::mem_fn(&X::f));
};

void h(std::vector<X *> const & v)
{
    std::for_each(v.begin(), v.end(), std::mem_fn(&X::f));
};

void k(std::vector<shared_ptr<X> > const & v)
{
    std::for_each(v.begin(), v.end(), std::mem_fn(&X::f));
};
int main()
{
	std::vector<X> v{X(0),X(1)};
 	X* x2=new X(2);X * x3= new X(3);
	std::vector<X*> v2{x2,x3};
	shared_ptr<X> x4(new X(4)),x5(new X(5));
	vector<shared_ptr<X>>v3{x4,x5};
	g(v);
	h(v2);
	k(v3);

}
