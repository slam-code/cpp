
#include "all.h"

/*
 *
 * 绝不在构造和析构过程中调用virtual函数。
 * */
class Transaction
{
public:
    Transaction()
    {
        logTransaction(); //调用了基类base的析构函数，而不是子类的析构函数。
        cout << "base 构造\n";
    };

    virtual void logTransaction() const
    { cout << "base log\n"; };
};

class BuyTransaction : public Transaction
{
public:
    BuyTransaction()
    { cout << "buy 构造\n"; }

    virtual void logTransaction() const //构造子类时，调用不到此函数。
    { cout << "buy log\n"; };
};

class SellTransaction : public Transaction
{
public:
    virtual void logTransaction() const;
};

void f()
{
    BuyTransaction *b = new BuyTransaction();

    delete b;
}

int main()
{

    f();
    return 0;
}