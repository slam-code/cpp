
#include "all.h"

/*
 * 不要让异常逃离析构函数
 * */

class DBConnection{
public:
    DBConnection()
    {}

    static DBConnection create()
    {}

    void close() //关闭连接，失败则抛出异常
    {
        throw "close() error ";
    };
    ~DBConnection(){

    }
};

/*为确保客户机不忘记调用DBConnection的close()函数:
 * 创建一个DBConn用于管理DBConnection的资源。并在析构函数中调用DBConnection的close().
 *
 * */
class DBConn
{
public:
    ~DBConn() //确保连接总是会被close。
    {
        db.close();
    }

private:
    DBConnection db;
};

/*
 * 上述代码正常情况下可以运行。但是如果 ~DBConn() 在调用close()时 close()发生了异常，
 * 那么析构函数会传播该异常，允许执行单元离开这个析构函数。就会造成析构函数异常不安全
 *
 * 解决方法:
 * 重写DBConnection，使其自身在析构时关闭链接。
 * 如果在 ~DBConnection()执行中，close()发生了异常，则捕获一切可能的异常。
 * 这样对 ~DBConnection()和  ~DBConn() 来说都是异常安全的。
 * */


int main()
{


    return 0;
}
