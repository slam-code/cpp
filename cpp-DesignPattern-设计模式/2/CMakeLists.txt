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

add_executable(dm1 dm10_抽象工厂模式.cpp)
add_executable(dm11 dm11_建造者模式_问题抛出.cpp)
add_executable(dm12 dm12_原型模式.cpp)
add_executable(dm12_2 dm12_建造者模式.cpp)
add_executable(dm13 dm13_代理模式a.cpp)
add_executable(dm14 dm14_装饰模式.cpp)

# add executable

# link libraries
#target_link_libraries( 100_same_tree )





