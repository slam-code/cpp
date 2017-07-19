cmake_minimum_required(VERSION 3.4)

project(leetcode C CXX)

SET (CMAKE_C_COMPILER  "/usr/bin/clang")
SET(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++ -lc++abi")

#set(SOURCE_FILES main.cpp)
include_directories ("${PROJECT_SOURCE_DIR}/")

aux_source_directory(. DIR_SRCS)
add_executable(leetcode ${SOURCE_FILES} ${DIR_SRCS}  )
target_link_libraries(leetcode )
#add_executable()
# add executable

# link libraries
#target_link_libraries( 100_same_tree )




