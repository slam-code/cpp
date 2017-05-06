cmake_minimum_required(VERSION 3.6)


project(Cpp_Concurrency_in_Action)
#SET (CMAKE_C_COMPILER  "/usr/bin/clang")
#SET(CMAKE_CXX_COMPILER "clang++")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -stdlib=libc++ -std=c++14  -lc++abi  -lboost_thread -lboost_system ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  --std=c++14 -lpthread  ")

set(SOURCE_FILES
        #listing_1.1.cpp
        listing_1.2.cpp
        #listing_10.1.cpp
        # listing_2.1.cpp
        #listing_2.2.cpp
        #   listing_2.3.cpp
        # listing_2.4.cpp
        #listing_2.5.cpp
        #listing_2.6.cpp
        #listing_2.7.cpp
        #listing_2.8.cpp
        #listing_2.8_id.cpp
        #listing_3.1.cpp
        #listing_3.10.cpp
        #listing_3.11.cpp
        #listing_3.12.cpp
        #listing_3.13.cpp
        #listing_3.2.cpp
        #listing_3.3.cpp
        # listing_3.4.cpp
        #listing_3.5.cpp
        #listing_3.6.cpp
        #listing_3.7.cpp
        #listing_3.8.cpp
        #listing_3.9.cpp
        #listing_4.1.cpp
        #listing_4.10.cpp
        #listing_4.11.cpp
        #listing_4.12.cpp
        #listing_4.13.cpp
        #listing_4.14.cpp
        #listing_4.15.cpp
        #listing_4.16.cpp
        #listing_4.2.cpp
        #listing_4.3.cpp
        #listing_4.4.cpp
        #listing_4.5.cpp
        #listing_4.6.cpp
        #listing_4.7.cpp
        #listing_4.8.cpp
        #listing_4.9.cpp
        #listing_5.1.cpp
        #listing_5.1.1.cpp
        #listing_5.1.2.cpp
        #listing_5.1.3.cpp
        #listing_5.10.cpp
        #listing_5.11.cpp
        #listing_5.12.cpp
        #listing_5.13.cpp
        #listing_5.2.cpp
        #listing_5.3.cpp
#        listing_5.2.1.cpp
       # listing_5.2.2_cas无锁链表.cpp
        #listing_5.4.cpp
        #listing_5.5.cpp
        #listing_5.6.cpp
        #listing_5.7.cpp
        #listing_5.8.cpp
        #listing_5.9.cpp
        listing_6.1.cpp
        #[[ listing_6.10.cpp
         listing_6.11.cpp
         listing_6.12.cpp
         listing_6.13.cpp
         listing_6.2.cpp
         listing_6.3.cpp
         listing_6.4.cpp
         listing_6.5.cpp
         listing_6.6.cpp
         listing_6.7.cpp
         listing_6.8.cpp
         listing_6.9.cpp
         listing_7.1.cpp
         listing_7.10.cpp
         listing_7.11.cpp
         listing_7.12.cpp
         listing_7.13.cpp
         listing_7.14.cpp
         listing_7.15.cpp
         listing_7.16.cpp
         listing_7.17.cpp
         listing_7.18.cpp
         listing_7.19.cpp
         listing_7.2.cpp
         listing_7.20.cpp
         listing_7.21.cpp
         listing_7.3.cpp
         listing_7.4.cpp
         listing_7.5.cpp
         listing_7.6.cpp
         listing_7.7.cpp
         listing_7.8.cpp
         listing_7.9.cpp
         listing_8.1.cpp
         listing_8.10.cpp
         listing_8.11.cpp
         listing_8.12.cpp
         listing_8.13.cpp
         listing_8.2.cpp
         listing_8.3.cpp
         listing_8.4.cpp
         listing_8.5.cpp
         listing_8.6.cpp
         listing_8.7.cpp
         listing_8.8.cpp
         listing_8.9.cpp
         listing_9.1.cpp
         listing_9.10.cpp
         listing_9.11.cpp
         listing_9.12.cpp
         listing_9.13.cpp
         listing_9.2.cpp
         listing_9.3.cpp
         listing_9.4.cpp
         listing_9.5.cpp
         listing_9.6.cpp
         listing_9.7.cpp
         listing_9.8.cpp
         listing_9.9.cpp
         listing_a.1.cpp
         listing_a.2.cpp
         listing_a.3.cpp
         listing_a.4.cpp
         listing_c.1.cpp
         listing_c.10.cpp
         listing_c.2.cpp
         listing_c.3.cpp
         listing_c.4.cpp
         listing_c.5.cpp
         listing_c.6.cpp
         listing_c.7.cpp
         listing_c.8.cpp
         listing_c.9.cpp]])

add_executable(Cpp_Concurrency_in_Action ${SOURCE_FILES})
target_link_libraries(Cpp_Concurrency_in_Action pthread)