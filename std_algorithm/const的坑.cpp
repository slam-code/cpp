http://haiyangxu.github.io/posts/2012/2012-11-08-cplusplus_constVariable.html
http://blog.csdn.net/eric_jo/article/details/4138548
http://blog.csdn.net/lihao21/article/details/8634876
http://www.programgo.com/article/84121384740/;jsessionid=EB1E7BD7532638F95A5E03F41AC9B4F9
http://blog.csdn.net/hongxiali/article/details/5208179


1）const成员函数可以访问非const对象的非const数据成员、const数据成员，也可以访问const对象内的所有数据成员；
2）非const成员函数可以访问非const对象的非const数据成员、const数据成员，但不可以访问const对象的任意数据成员；
3）作为一种良好的编程风格，在声明一个成员函数时，若该成员函数并不对数据成员进行修改操作，应尽可能将该成员函数声明为const 成员函数。
4) const对象，指向const对象的指针或引用只能调用其const成员函数