//
//#include <iostream>
//using namespace std;
//
//// MyIterator  Aggregate ContreteIterator ConcreteAggregate
//
////	a	 b	c	d
////      ▲
//
//
//typedef int Object ;
//#define SIZE 5
//
//class MyIterator
//{
//public:
//	virtual void First() = 0;
//	virtual void Next() = 0;
//	virtual bool IsDone() = 0;
//	virtual Object CurrentItem() = 0;
//};
//
//class Aggregate
//{
//public:
//	virtual MyIterator *CreateIterator() = 0;
//	virtual Object getItem(int index) = 0;
//	virtual int getSize() = 0;
//};
//
//class ContreteIterator : public MyIterator
//{
//public:
//	ContreteIterator(Aggregate *ag)
//	{
//		_ag = ag;
//		_current_index = 0;
//	}
//	virtual void First()
//	{
//		_current_index = 0;  //让当前 游标 回到位置0
//	}
//	virtual void Next()
//	{
//		if (_current_index < _ag->getSize())
//		{
//			_current_index ++;
//		}
//	}
//	virtual bool IsDone()
//	{
//		return  (_current_index ==  _ag->getSize());
//	}
//	virtual Object CurrentItem()
//	{
//		return _ag->getItem(_current_index);
//	}
//protected:
//private:
//	int			_current_index;
//	Aggregate	 *_ag;
//};
//
//
//class ConcreteAggregate : public Aggregate
//{
//public:
//	ConcreteAggregate()
//	{
//		for (int i=0; i<SIZE; i++)
//		{
//			object[i] = i + 100;
//		}
//	}
//	virtual MyIterator *CreateIterator()
//	{
//		return new ContreteIterator(this); //让迭代器 持有一个 集合的 引用
//	}
//	virtual Object getItem(int index)
//	{
//		return object[index];
//	}
//	virtual int getSize()
//	{
//		return SIZE;
//	}
//private:
//	Object object[SIZE];
//};
//
//int main()
//{
//	Aggregate * ag = new ConcreteAggregate;
//
//	MyIterator *it = ag->CreateIterator();
//
//	for (; !(it->IsDone()); it->Next() )
//	{
//		cout << it->CurrentItem() << " ";
//	}
//
//	delete it;
//	delete ag;
//
//}

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

/*请完成下面这个函数，实现题目要求的功能*/
/*当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ */
/******************************开始写代码******************************/
double StockGod(int n, int m, double p, const vector<vector<double>>& prices)
{

}
/******************************结束写代码******************************/


int main()
{
	int n = 0;
	int m = 0;
	double p = 0;
	cin >> n >> m >> p;

	vector<vector<double>> prices;
	for(int i = 0; i < m; ++i) {
		prices.push_back(vector<double>());
		for(int j = 0; j < n; ++j) {
			double x = 0;
			cin >> x;
			prices.back().push_back(x);
		}
	}

	double final = StockGod(n, m, p, prices);
	printf("%.1f\n", final);

	return 0;
}