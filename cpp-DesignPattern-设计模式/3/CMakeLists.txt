cmake_minimum_required(VERSION 3.4)

project(Designpattern C CXX)

#[[SET (CMAKE_C_COMPILER  "/usr/bin/clang")
SET(CMAKE_CXX_COMPILER "clang++")]]
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++ -lc++abi -fpermissive")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -fpermissive -std=c++11 ")
#set(SOURCE_FILES main.cpp)
include_directories ("${PROJECT_SOURCE_DIR}/")

aux_source_directory(. DIR_SRCS)
add_executable(Designpattern ${SOURCE_FILES} ${DIR_SRCS}  )
target_link_libraries(Designpattern )

add_executable(dm20 dm20_模板模式.cpp)


add_executable(dm30 dm30_迭代器模式.cpp)
add_executable(net2 net2.cpp)
add_executable(al1 ali1.cpp)
add_executable(3 3.cpp)

# add executable

# link libraries
#target_link_libraries( 100_same_tree )





