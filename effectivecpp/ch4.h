//
// Created by shen on 16-9-15.
//

#ifndef EFFECTIVECPP_CH4_H
#define EFFECTIVECPP_CH4_H

namespace ch4 {
#include "all.h"

    class PhoneNumber {

    };

    class ABEntry {
    public:
        ABEntry(string &name, string &address, list <PhoneNumber> &phone);

        ABEntry(const string &name, string &address, list <PhoneNumber> &phone);

        ABEntry(string &name, const string &address, list <PhoneNumber> &phone);

        ABEntry();

    private:
        string theName;
        string theAddress;
        list <PhoneNumber> thePhone;
        int numtimesconsulted;
    };

    ABEntry::ABEntry(string &name, string &address, list <PhoneNumber> &phone) {
        theName = name;//这些都是赋值，而非初始化！
        theAddress = address;
        thePhone = phone;
        numtimesconsulted = 0;
    }

    ABEntry::ABEntry(const string &name, string &address, list <PhoneNumber> &phone) :
            theName(name),//现在这些都是初始化！初值列
            theAddress(address),
            thePhone(phone),
            numtimesconsulted(0) {}

//无参构造函数
    ABEntry::ABEntry() :
            theName(),//调用theName()default构造函数
            theAddress(),//类似
            thePhone(),//类似
            numtimesconsulted(0)//显示初始化
    {};



//non-local-static对象

    class FileSystem {
    public:
        size_t numDisks() const {
            cout << "num=:" << num << endl;
            return num;
        };
    private:
        int num = 0;
    };

    FileSystem tfs;

    class Directory {
    public:
        Directory(int a);

        Directory(double a);

    };

    Directory::Directory(int a) {
        size_t disks = tfs.numDisks();
        cout << "disks=: " << disks << endl;
    }

    void f2() {
        Directory tempdir(2);
    }


    //单例模式
    FileSystem &tfs2() {
        static FileSystem fs;
        return fs;
    }

    Directory::Directory(double a) {
        size_t disks = tfs2().numDisks();
    }

    Directory& tempdir2()
    {
        static Directory td(1.1);
        return td;
    }

}


#endif //EFFECTIVECPP_CH4_H
