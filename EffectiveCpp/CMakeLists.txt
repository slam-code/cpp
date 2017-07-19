cmake_minimum_required(VERSION 3.5)
project(effectivecpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -w")
SET (CMAKE_C_COMPILER  "/usr/bin/clang")
SET(CMAKE_CXX_COMPILER "clang++")
aux_source_directory(. DIR_SRCS)
include_directories ("${PROJECT_SOURCE_DIR}/")

#add_executable(muduo_ ${SOURCE_FILES} ${DIR_SRCS})
#set(SOURCE_FILES main.cpp ch2.h ch3.h ch3_cast转型.h all.h ch4.h ch5.h ch6.h ch7.h ch9.h ch10.h Thread.cpp Thread.h TestThread.h   Thread_base_object.h Thread_base_object_test.h ch12.h)
add_executable(effectivecpp ${DIR_SRCS} ch13.h ch14.h ch15.h ch16.h ch20.h ch21.h)
target_link_libraries(effectivecpp pthread)