cmake_minimum_required(VERSION 3.6)


project(Cpp_Concurrency_in_Action)
SET (CMAKE_C_COMPILER  "/usr/bin/clang")
SET(CMAKE_CXX_COMPILER "clang++")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -stdlib=libc++ -std=c++14  -lc++abi  -lboost_thread -lboost_system ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  --std=c++1z -lpthread  -stdlib=libc++  -lc++abi    ")
add_subdirectory(ch1)
add_subdirectory(ch2)
add_subdirectory(ch3)
add_subdirectory(ch4)