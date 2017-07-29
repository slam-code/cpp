
#include <iostream>
using namespace std;
#include "string"
#include "list"

class IFile
{
public:
	virtual void display() = 0;
	virtual int add(IFile *ifile) = 0;
	virtual int remove(IFile *ifile) = 0;
	virtual list<IFile *>* getChild() = 0;
};

//文件结点
class File : public IFile
{
public:
	File(string name)
	{
		m_name = name;
	}
	virtual void display()
	{
		cout << m_name << endl;
	}

	virtual int add(IFile *ifile)
	{
		return -1;
	}

	virtual int remove(IFile *ifile)
	{
		return -1;
	}

	virtual list<IFile *>*  getChild()
	{
		return NULL;
	}
private:
	string m_name;
};

//目录 结点
class Dir : public IFile
{
public:
	Dir(string name)
	{
		m_name = name;
		m_list = new list<IFile *>;
		m_list->clear();
	}
	virtual void display()
	{
		cout << m_name << endl;
	}

	virtual int add(IFile *ifile)
	{
		m_list->push_back(ifile);
		return 0;
	}

	virtual int remove(IFile *ifile)
	{
		m_list->remove(ifile);
		return 0;
	}

	virtual list<IFile *>*  getChild()
	{
		return m_list;
	}
private:
	string m_name;
	list<IFile *>  *m_list;
};


// 递归的显示树
void showTree(IFile *root, int level)
{
	int i = 0;
	if (root == NULL)
	{
		return ;
	}
	for (i=0; i<level; i++)
	{
		printf("\t");
	}
	//1 显示根 结点
	root->display();

	//2  若根结点 有孩子
	//判读孩子是文件,显示名字 )
	//判断孩子是目录,showTree(子目录)

	list<IFile *>  *mylist = root->getChild();
	if (mylist != NULL) //说明是一个目录
	{
		for (list<IFile *>::iterator it=mylist->begin(); it!=mylist->end(); it++)
		{
			if ( (*it)->getChild() == NULL )
			{
				for (i=0; i<=level; i++) //注意 <=
				{
					printf("\t");
				}
				(*it)->display();
			}
			else
			{
				showTree(*it, level+1);
			}
		}
	}
}

int main()
{
	Dir *root = new Dir("C");
	//root->display();

	Dir *dir1 = new Dir("111dir");
	File *aaafile = new File("aaa.txt");

	//获取root结点下的 孩子集合
	list<IFile *>  *mylist =  root->getChild();

	root->add(dir1);
	root->add(aaafile);

	//  (111dir)   (aaa.txt)
	//				▲
	for ( list<IFile *>::iterator it=mylist->begin(); it!=mylist->end(); it++ )
	{
		(*it)->display();
	}

	//
	Dir *dir222 = new Dir("222dir");
	File *bbbfile = new File("bbb.txt");
	dir1->add(dir222);
	dir1->add(bbbfile);

	cout << "通过 showTree 方式 显示 root 结点下的 所有子结点" << endl;

	showTree(root, 0);
}