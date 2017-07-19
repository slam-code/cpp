//clang++ SAD自动微分.cpp -std=c++11
//https://www.zhihu.com/question/48356514
#include <cmath>
#include <vector>
#include <iostream>
namespace SAD  // Simple Automatic Differentiation
{
	class ADV
	{
	public:
		ADV(double v = 0, double d = 0);

		// overloaded unary and binary operators
		ADV operator + (const ADV &x) const;
		ADV operator - (const ADV &x) const;
		ADV operator * (const ADV &x) const;
		friend ADV sin(const ADV &x);
		friend ADV cos(const ADV &x);

		double val;  // value of the variable
		double dval;  // derivative of the variable
	};

	ADV::ADV(double v, double d) : val(v), dval(d) {}

	ADV ADV::operator+(const ADV &x) const
	{
		ADV y;
		y.val = val + x.val;
		y.dval = dval + x.dval;
		return y;
	}

	ADV ADV::operator-(const ADV &x) const
	{
		ADV y;
		y.val = val - x.val;
		y.dval = dval - x.dval; // sum rule
		return y;
	}

	ADV ADV::operator*(const ADV &x) const
	{
		ADV y;
		y.val = val*x.val;
		y.dval = x.val*dval + val*x.dval; // product rule
		return y;
	}

	ADV sin(const ADV &x)
	{
		ADV y;
		y.val = std::sin(x.val);
		y.dval = std::cos(x.val)*x.dval; // chain rule
		return y;
	}

	ADV cos(const ADV &x)
	{
		ADV y;
		y.val = std::cos(x.val);
		y.dval = -std::sin(x.val)*x.dval; // chain rule
		return y;
	}
}


int main()
{
	using namespace SAD;
	using namespace std;

	static const double PI = 3.1415926;
	vector<ADV> x;

	x.emplace_back(PI, 1);  // x = [PI, 2, 1]
	x.emplace_back(2, 0);
	x.emplace_back(1, 0);

	ADV y1 = cos(x[0]);
	ADV y2 = sin(x[0]);
	ADV y3 = x[1] * y1;
	ADV y4 = x[2] * y2;
	ADV y5 = x[1] * y2;
	ADV y6 = x[2] * y1;

	ADV z1 = y3 + y4;
	ADV z2 = y6 - y5;

	cout << "x = [" << x[0].val << ", " << x[1].val << ", " << x[2].val << "]" << endl;
	cout << "z = [" << z1.val << ", " << z2.val << "]" << endl;
	cout << "[dz1/dx0, dz2/dx0] = [" << z1.dval << "," << z2.dval << "]" << endl;
}
