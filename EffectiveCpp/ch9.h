//
// Created by shen on 16-9-15.
//

#ifndef EFFECTIVECPP_CH9_H
#define EFFECTIVECPP_CH9_H

#include "all.h"

namespace  ch9{
    class Transaction{
    public:
        Transaction(){logTransaction();cout<<"base 构造\n";};
        virtual void logTransaction() const{cout<<"base log\n";};
    };

    class BuyTransaction:public Transaction{
    public:
        BuyTransaction(){cout<<"buy 构造\n";}
        virtual void logTransaction()const{cout<<"buy log\n";};
    };

    class SellTransaction:public Transaction{
    public:
        virtual void logTransaction()const;
    };

    void f()
    {
        BuyTransaction* b=new BuyTransaction();
        delete b;
    }
}
#endif //EFFECTIVECPP_CH9_H
