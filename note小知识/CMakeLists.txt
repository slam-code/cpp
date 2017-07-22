cmake_minimum_required(VERSION 3.6)


project(Cpp_note)

SET (CMAKE_C_COMPILER  "/usr/bin/clang")
SET(CMAKE_CXX_COMPILER "clang++")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++14 -lpthread    ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++14 -lpthread  -stdlib=libc++  -lc++abi    ")

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -stdlib=libc++ -std=c++14  -lc++abi  -lboost_thread -lboost_system ")

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++14 -lpthread ")

add_executable(1cppClass_InnerClass  1cppClass_InnerClass内部类对外的访问权.cpp)
add_executable(2coredump 2coredump产生的原因.cpp)
add_executable(4_Endian 4_Endian-判断处理器使用的什么模式.cpp)
add_executable(5_virtual 5_virtual_虚函数的实现机制.cpp)
add_executable(6-vector 6-vector-构造函数.cpp)
add_executable(6-simple_vector 6-simple_vector.cpp)