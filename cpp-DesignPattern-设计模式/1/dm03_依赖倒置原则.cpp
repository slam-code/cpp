
#include <iostream>
using namespace std;

//让 Computer框架  和 具体的厂商 进行接耦合

class  HardDisk
{
public:
    virtual void work() = 0;
};

class  Memory
{
public:
    virtual void work() = 0;
};

class  Cpu
{
public:
    virtual void work() = 0;
};

class Computer
{
public:
    Computer(HardDisk *handdisk, Memory *memory, Cpu *cpu)
    {
        m_handdisk = handdisk;
        m_memory = memory;
        m_cpu = cpu;
    }
    // HardDisk
    // Memory
    // Cpu
public:
    void work()
    {
        m_handdisk->work();
        m_memory->work();
        m_cpu->work();
    }
protected:
private:
    HardDisk *m_handdisk;
    Memory *m_memory;
    Cpu *m_cpu;
};


class  InterCpu : public Cpu
{
public:
    void work()
    {
        cout << "我是iterl cpu 我工作良好" << endl;
    }
};


class  XSDisk : public HardDisk
{
public:
    void work()
    {
        cout << "我是西数硬盘 工作良好" << endl;
    }
};

class  JSDMem : public Memory
{
public:
    void work()
    {
        cout << "JSDMem 工作良好" << endl;
    }
};

int main()
{
    HardDisk * harddisk = NULL;
    Memory * memory = NULL;
    Cpu * cpu = NULL;

    harddisk = new XSDisk;
    memory  = new JSDMem;
    cpu = new InterCpu;

    Computer *mycomputer = new Computer(harddisk ,memory,  cpu);

    mycomputer->work();

    delete mycomputer;
    delete cpu;
    delete memory;
    delete harddisk;



}

// 1.java ====> 1.class
//1.c ===> obj汇编
class A
{
public:
    void doA()
    {

    }

    void doB()
    {

    }
protected:
private:
};


class B : public A
{
public:
    void doB()
    {

    }
protected:
private:
};


class C
{
public:
    C(A *a)
    {

    }

    void setA(A *a)
    {
        this->a = a;
    }

private:
    A *a;
};

//java 3 aop编程