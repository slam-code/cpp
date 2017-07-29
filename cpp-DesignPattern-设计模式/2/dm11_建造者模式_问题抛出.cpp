
#include <iostream>
using namespace std;
#include "string"

class House
{
public:
	void setDoor(string door)
	{
		this->m_door = door;
	}

	void setWall(string wall)
	{
		this->m_wall = wall;
	}
	void setWindow(string window)
	{
		this->m_window = window;
	}

	//--
	string getDoor( )
	{
		cout << m_door << endl;
		return this->m_door ;
	}

	string getWall()
	{
		cout << m_wall << endl;
		return this->m_wall;
	}
	string getWindow()
	{
		cout << m_window << endl;
		return m_window;
	}

private:
	string	m_door;
	string	m_wall;
	string	m_window;
};


class Build
{
public:
	Build()
	{
		m_house = new House;
	}

	void makeBuild()
	{
		buildDoor(m_house);
		buildWall(m_house);
		buildWindow(m_house);
	}
	void buildDoor(House *h)
	{
		h->setDoor("门");
	}
	void buildWall(House *h)
	{
		h->setWall("墙");
	}
	void buildWindow(House *h)
	{
		h->setWindow("窗");
	}

	House *getHouse()
	{
		return m_house;
	}

private:
	House *m_house;

};

int main()
{
	/* 客户直接造房子
	House *house = new House;
	house->setDoor("门");
	house->setWall("墙面");
	house->setWindow("窗口");
	delete house;
	*/

	//请工程队 建造房子
	House *house = NULL;
	Build * build = new Build;
	build->makeBuild();
	house = build->getHouse();
	house->getDoor();
	house->getWall();
	house->getWindow();
}