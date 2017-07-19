//
// Created by shen on 16-9-19.
//

#ifndef EFFECTIVECPP_CH12_H
#define EFFECTIVECPP_CH12_H

#include <string>
class Date{};
static int i=0;
void logCall(const std::string& funcName){printf("logcall %d \n",i++);};

class Customer{
public:
    Customer()= default;
    Customer(std::string name_,int i_):name(name_),lastaction(i_){};
    Customer(const Customer& rhs):name(rhs.name),lastaction(rhs.lastaction){
        logCall("Customer copy constructor ");
    };
    Customer&operator=(const Customer& rhs){
        logCall("Customer copy assigment operator");
        name=rhs.name;
        lastaction=rhs.lastaction;
        return *this;
    };

private:
    std::string name;
    int lastaction;//新增成员
};

class PriorityCustomer:public Customer{ //子类定义拷贝构造函数时，必须考虑基类拷贝构造
public:
    PriorityCustomer(int pr):priority(pr){};
    PriorityCustomer(const PriorityCustomer& rhs):Customer(rhs),priority(rhs.priority){
        logCall("prioritycustomer copy ");
    }
    PriorityCustomer&operator=(const PriorityCustomer& rhs){
        logCall("prioritycustomer copy assignment ");
        Customer::operator=(rhs);
        priority=rhs.priority;
        return *this;
    }
private:
    int priority;
};

void f12(){

    Customer c("helo",2);
    PriorityCustomer s(4);
    PriorityCustomer s2(s);
}
#endif //EFFECTIVECPP_CH12_H
