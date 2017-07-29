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

add_executable(dm01 dm01_类和类之间的关系.cpp)
add_executable(dm02 dm02_开闭原则.cpp)
add_executable(dm03 dm03_依赖倒置原则.cpp)
add_executable(dm04 dm04_单例_懒汉式.cpp)
add_executable(dm05 dm05_单例_饿汉式.cpp)
add_executable(dm08 dm08_简单工厂模式.cpp)
add_executable(dm09 dm09_抽象工厂模式.cpp)
# add executable

# link libraries
#target_link_libraries( 100_same_tree )





