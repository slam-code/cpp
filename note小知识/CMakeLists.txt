cmake_minimum_required(VERSION 3.6)


project(Cpp_note)

SET (CMAKE_C_COMPILER  "/usr/bin/clang")
SET(CMAKE_CXX_COMPILER "clang++")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++14 -lpthread    ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++14 -lpthread  -stdlib=libc++  -lc++abi    ")

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -stdlib=libc++ -std=c++14  -lc++abi  -lboost_thread -lboost_system ")

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++14 -lpthread ")

add_executable(0.1.1-rvo 0.1.1-rvo优化.cpp)
add_executable(1cppClass_InnerClass  1cppClass_InnerClass内部类对外的访问权.cpp)
add_executable(2coredump 2coredump产生的原因.cpp)
add_executable(4_Endian 4_Endian-判断处理器使用的什么模式.cpp)
add_executable(5_virtual 5_virtual_虚函数的实现机制.cpp)
add_executable(6-vector 6-vector-构造函数.cpp)
add_executable(6-simple_vector 6-simple_vector.cpp)
add_executable(6-list_clear  6-list_clear自定义类与指针.cpp)
add_executable(7-point_to_function_point 7-point_to_function_point指向函数指针的指针.cpp)
add_executable(7-point-refer 8-point-refer.cpp)
add_executable(7-point-refer2 7-point-refer2.cpp)
add_executable(7-function_point3 7-function_point3.cpp)
add_executable(7-refer 8-refer函数传引用.cpp)
add_executable(8-cpp_rvalue 8-cpp_rvalue右值.cpp)
add_executable(9-pair 9-pair.cpp)