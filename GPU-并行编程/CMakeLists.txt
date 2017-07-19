
# CMakeLists.txt for G4CU project
project(test_cuda_project)
# required cmake version
cmake_minimum_required(VERSION 2.8)
# packages
find_package(CUDA)
# nvcc flags
set(CUDA_NVCC_FLAGS -gencode arch=compute_20,code=sm_20;-G;-g)
#set(CUDA_NVCC_FLAGS -gencode arch=compute_52,code=sm_52;-G;-g)

file(GLOB_RECURSE CURRENT_HEADERS  *.h *.hpp *.cuh)
file(GLOB CURRENT_SOURCES  *.cpp *.cu)
source_group("Include" FILES ${CURRENT_HEADERS}) 
source_group("Source" FILES ${CURRENT_SOURCES}) 

CUDA_ADD_EXECUTABLE(test_cuda_project ${CURRENT_HEADERS} ${CURRENT_SOURCES})

