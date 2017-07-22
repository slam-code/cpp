cmake_minimum_required(VERSION 3.6)


project(Cpp_note)

SET (CMAKE_C_COMPILER  "/usr/bin/clang")
SET(CMAKE_CXX_COMPILER "clang++")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++14 -lpthread    ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++14 -lpthread  -stdlib=libc++  -lc++abi    ")

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -stdlib=libc++ -std=c++14  -lc++abi  -lboost_thread -lboost_system ")

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++14 -lpthread ")

add_executable(cppClass_InnerClass  cppClass_InnerClass内部类对外的访问权.cpp)