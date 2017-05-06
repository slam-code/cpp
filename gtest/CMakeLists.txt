#[[ #2016.5
cmake_minimum_required(VERSION 2.8.7)

project(gtest  C CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -w -fpermissive")

set(SOURCE_FILES  gtest.h gtest-all.cpp gtest_main.cc)
add_library(gtest STATIC  gtest.h gtest-all.cpp)
add_executable(gtest ${SOURCE_FILES} ${DIR_SRCS})
target_link_libraries(gtest pthread  )
#add_library(gtest_main gtest_main.cc)
#target_link_libraries(gtest_main gtest)]]


#[[cmake_minimum_required(VERSION 3.0)#2016

project(test_gtest C CXX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread -std=c++11 -w -fpermissive")

set(SOURCE_FILES gtest.h gtest-all.cpp gtest_main.cc)

#aux_source_directory(. DIR_SRCS)

#add_library(test_gtest ${DIR_SRCS})

add_executable(test_gtest ${SOURCE_FILES} ${DIR_SRCS})]]



#2017
project(test_gtest C CXX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread -std=c++11 -w -fpermissive")

aux_source_directory(./smaples/ DIR_SRCS)
#set(SOURCE_FILES  gtest.h gtest-all.cpp gtest_main.cc)
add_library(gtest STATIC  gtest.h gtest-all.cpp)

add_executable(gtest_main gtest_main.cc)

target_link_libraries(gtest_main gtest)
