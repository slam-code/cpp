#include <iostream>
#include <vector>

using namespace std;

class OutClass
{

public:
    OutClass()
    {
        OutData=new int(0);
    }
    void Setdata(int num)
    {
        *OutData = num;

    }

    int *Getdata()
    {
        return OutData;
    }

    class InnerClass_public
    {
    public:
        /*  int* getdata() //编译不通过，不能直接访问
          {
              return OutData;
          }
        */

        void getdatabyfunction(OutClass out, int num) //编译通过，可以直接访问。
        {
            InnerData = out.OutData;
            *InnerData = num;
        }

    private:
        int *InnerData = nullptr;
    };

private:

    class InnerClass_private
    {
    public:
        /*  int* getdata() //编译不通过
          {
              return OutData;
          }
        */

        void getdatabyfunction(OutClass out, int num) //编译通过。
        {
            InnerData = out.OutData;
            *InnerData = num;
        }

    private:
        int *InnerData = nullptr;
    };

    int *OutData = nullptr;
};

int main()
{

    OutClass out;

    out.Setdata(1);

    // public域的内部类，可以访问。
    OutClass::InnerClass_public innerClass_public;


    cout << *out.Getdata() << endl;

    innerClass_public.getdatabyfunction(out, 2);

    cout << *out.Getdata() << endl;

    // private域的内部类，不可访问。
    /*
    OutClass::InnerClass_private innerClass_private;
    innerClass_private.getdatabyfunction(out, 3);
    cout << *out.Getdata() << endl;*/


}