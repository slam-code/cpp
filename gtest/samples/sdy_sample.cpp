//
// Created by shen on 16-10-12.
//编译：g++ sdy_sample.cpp  -I../ libgtest.a  -lpthread
// g++ gtest_main sample1.o  libgtest.a -o main -lpthread
#include "../gtest.h"

int Foo(int a, int b) { //这个函数的作用是求两个数的最大公约数。
    if(a == 0 || b == 0) {
        throw "Don't do that.";
    }
    int c = a % b;
    if(c == 0)
        return b;
    return Foo(b, c);
}

//下面我们来编写一个简单的测试案例
//对于检查点的检查，我们用到了 EXPECT_EQ 宏，这个宏用来比较两个数字是否相等。
TEST(FooTest, HandleNoneZeroInput){
    EXPECT_EQ(2, Foo(4, 10));
    EXPECT_EQ(6, Foo(30, 18));
}
TEST(FooTest, sdy){
    EXPECT_EQ(2, Foo(3, 10));
    EXPECT_EQ(6, Foo(30, 18));
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}