
cmake_minimum_required(VERSION 3.0)#2016

project(test_gtest C CXX)
SET (CMAKE_C_COMPILER  "/usr/bin/clang")
SET(CMAKE_CXX_COMPILER "clang++")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread -std=c++11 -w -fpermissive")

#set(SOURCE_FILES  gtest.h gtest-all.cpp gtest_main.cc)

aux_source_directory(. DIR_SRCS)

add_library(gtest STATIC  ../gtest.h ../gtest-all.cpp)

add_executable(gtest_main ../gtest_main.cc)
target_link_libraries(gtest_main gtest)

add_executable(sample1_unittest ../gtest_main.cc sample1_unittest.cpp sample1.cpp)
target_link_libraries(sample1_unittest gtest)

add_executable(1_sample 1_sample.cpp )
target_link_libraries(sdy_sample gtest)

add_executable(sample2_unittest ../gtest_main.cc  sample2_unittest.cc sample2.cc )
target_link_libraries(sample2_unittest gtest)
