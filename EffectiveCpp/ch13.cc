
#include <all.h>
class Inverstment
{

};

Inverstment *CreateInverstment() //工厂函数。
{
    return new Inverstment();
};

void f13()
{

    std::shared_ptr<Inverstment> pinv(CreateInverstment());//shared_ptr自动调用析构函数，删除pinv



    //自己手动管理内存
    Inverstment *pInv = CreateInverstment();
    delete pInv;//该语句可能不会执行，则内存泄漏
}

int main()
{

    f13();
    return 0;
}