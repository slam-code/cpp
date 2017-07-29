
#include <all.h>

/*
 * 复制一个对象时，勿忘记每一个部分
 * */
class Date
{
};

static int i = 0;

void logCall(const std::string &funcName)
{ printf("log call %d \n", i++); };

class Customer
{
public:
    Customer() = default;

    Customer(std::string name_, int i_) : name(name_), lastaction(i_)
    {};

    //拷贝每一部分。
    Customer(const Customer &rhs) : name(rhs.name), lastaction(rhs.lastaction)
    {
        logCall("Customer copy constructor ");
    };

    Customer &operator=(const Customer &rhs)
    {
        logCall("Customer copy assigment operator");
        name = rhs.name;
        lastaction = rhs.lastaction;
        return *this;
    };

private:
    std::string name;
    int lastaction;//新增成员
};

class PriorityCustomer : public Customer
{ //子类定义拷贝构造函数时，必须考虑基类拷贝构造
public:
    PriorityCustomer(int pr) : priority(pr)
    {};

    PriorityCustomer(const PriorityCustomer &rhs) : Customer(rhs), priority(rhs.priority)
    {
        logCall("prioritycustomer copy ");
    }

    PriorityCustomer &operator=(const PriorityCustomer &rhs)
    {
        logCall("prioritycustomer copy assignment ");
        Customer::operator=(rhs);//显式调用父类的operator=()函数。
        priority = rhs.priority;
        return *this;
    }

private:
    int priority;
};

void f12()
{

    Customer c("helo", 2);
    PriorityCustomer s(4);
    PriorityCustomer s2(s);
}

int main()
{


    f12();
    return 0;
}