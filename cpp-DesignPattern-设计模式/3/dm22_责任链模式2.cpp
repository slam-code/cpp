
#include <iostream>
using namespace std;

/*
struct Teacher
{
	char name;
	int age;
	Teacher *next;
};
*/

//造完车 以后,需要把任务 传递下去
class CarHandle
{
public:
	virtual void HandleCar() = 0;
	CarHandle *setNextHandle(CarHandle *handle)
	{
		m_handle = handle;
		return m_handle;
	}
	
protected:
	CarHandle *m_handle;  //下一个处理单元
};

class HeadCarHandle : public CarHandle
{
public:
	virtual void HandleCar()
	{
		cout << "造车头" << endl;
		//造 玩车头 以后 把任务递交给 下一个处理者
		if (m_handle != NULL) 
		{
			m_handle->HandleCar(); //
		}
	}
};

class BodyCarHandle : public CarHandle
{
public:
	virtual void HandleCar()
	{
		cout << "造 车身" << endl;
		//造 造 车身 以后 把任务递交给 下一个处理者
		if (m_handle != NULL) 
		{
			m_handle->HandleCar(); //
		}

	}
};

class TailCarHandle : public CarHandle
{
public:
	virtual void HandleCar()
	{
		cout << "造车尾" << endl;
		//造 造车尾 以后 把任务递交给 下一个处理者
		if (m_handle != NULL) 
		{
			m_handle->HandleCar(); //
		}
	}
};


void main()
{
	CarHandle *headHandle = new HeadCarHandle;
	CarHandle *bodyHandle = new BodyCarHandle;
	CarHandle *tailHandle = new TailCarHandle;

	//任务的处理关系
	/*
	headHandle->setNextHandle(bodyHandle);
	bodyHandle->setNextHandle(tailHandle);
	tailHandle->setNextHandle(NULL);
	*/

		
	headHandle->setNextHandle(tailHandle);
	tailHandle->setNextHandle(bodyHandle);
	bodyHandle->setNextHandle(NULL);
	
	headHandle->HandleCar();

	/*
	//业务逻辑 写死在客户端了..
	headHandle->HandleCar();
	bodyHandle->HandleCar();
	tailHandle->HandleCar();
	*/

	delete headHandle;
	delete bodyHandle;
	delete tailHandle;

	cout<<"hello..."<<endl;
	system("pause");
	return ;
}