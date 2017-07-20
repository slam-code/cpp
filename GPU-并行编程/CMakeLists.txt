# CMakeLists.txt for G4CU project
project(test_cuda_project)
# required cmake version
cmake_minimum_required(VERSION 2.8)

#SET (CMAKE_C_COMPILER  "/usr/bin/clang")
#SET(CMAKE_CXX_COMPILER "/usr/bin/clang++")
#
enable_language(CXX)
#
#enable_language(C)


# packages
find_package(CUDA)
# nvcc flags
#set(CUDA_NVCC_FLAGS -gencode arch=compute_20,code=sm_20;-G;-g)
#set(CUDA_NVCC_FLAGS -gencode arch=compute_52,code=sm_52;-G;-g)
set(CUDA_NVCC_FLAGS -gencode arch=compute_30,code=sm_30;-G;-g)

set(CUDA_NVCC_FLAGS -w)


CUDA_ADD_EXECUTABLE(test_vec vectorAdd.cu )
CUDA_ADD_EXECUTABLE(what_is_my_id what_is_my_id.cu)
CUDA_ADD_EXECUTABLE(what_is_my_id_2D_A what_is_my_id_2D_A.cu)




#file(GLOB_RECURSE CURRENT_HEADERS  *.h *.hpp *.cuh)
#file(GLOB CURRENT_SOURCES  *.cpp *.cu)
#source_group("Include" FILES ${CURRENT_HEADERS}) 
#source_group("Source" FILES ${CURRENT_SOURCES}) 

#CUDA_ADD_EXECUTABLE(test_cuda_project ${CURRENT_HEADERS} ${CURRENT_SOURCES})