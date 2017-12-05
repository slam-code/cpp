shell+vim+git+find+grep+收log
gdb+strace+log+valgrind

log4cplus
cppuint

googlemock 和 googletest 有什么关系:
googletest是一个类似于unittest等的单元测试框架。可以对，类，函数等的功能进行测试。很好用。
googlemock 是googletest的一个辅助框架，用于当类（A）没有编写时，造一个假类（MockA）模拟A的操作，以免必须A完成后才能测试。当然MOckA和A的接口要协商好，以免二者不匹配。一般情况下只用googletest 就可以了。
