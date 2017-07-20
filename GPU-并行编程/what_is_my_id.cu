#include<stdio.h>
#include <stdlib.h>
//#include <conio.h>
#ifndef __host__
    #define __host__
    #define __device__
    #define __global__
    #define __CUDACC__
    #define __host__
    #define __device__
    #define __global__
    #define __forceinline__
    #define __shared__

    inline void __syncthreads()
    {}

    inline void __threadfence_block()
    {}

    template<class T>
    inline T __clz(const T val)
    { return val; }

    struct __cuda_fake_struct
    {
        int x;
    };
    extern __cuda_fake_struct blockDim;
    extern __cuda_fake_struct threadIdx;
    extern __cuda_fake_struct blockIdx;
    #define cudaMemcpy
    #define  cudaMalloc
    #define warpSize
    #define cudaFree

    #define cudaMemcpyDeviceToHost
#endif

__global__ void what_is_my_id(unsigned int *const block, unsigned int *const thread,
                              unsigned int *const wrap, unsigned int *calc_thread)
{
    const unsigned int thread_idx = (blockIdx.x * blockDim.x) + threadIdx.x;
    block[thread_idx] = blockIdx.x;
    thread[thread_idx] = threadIdx.x;
    wrap[thread_idx] = threadIdx.x / warpSize;
    calc_thread[thread_idx] = thread_idx;
};

#define ARRAY_SIZE 128
#define ARRAY_SIZE_IN_BYTES (sizeof(unsigned int )* (ARRAY_SIZE))
unsigned int cpu_block[ARRAY_SIZE];
unsigned int cpu_thread[ARRAY_SIZE];
unsigned int cpu_warp[ARRAY_SIZE];
unsigned int cpu_calc_thread[ARRAY_SIZE];
/*
 * 写一个简短的内核程序来输出线程块，线程，线程束，线程全局标号。
 * */
int main()
{
    const unsigned int num_blocks = 2;//线程块
    const unsigned int num_threads = 64;//每块的线程数
    char ch;
    unsigned int *gpu_block;
    unsigned int *gpu_thread;
    unsigned int *gpu_warp;
    unsigned int *gpu_calc_thread;
    unsigned int i;
    cudaMalloc((void **) &gpu_block, ARRAY_SIZE_IN_BYTES);
    cudaMalloc((void **) &gpu_thread, ARRAY_SIZE_IN_BYTES);
    cudaMalloc((void **) &gpu_warp, ARRAY_SIZE_IN_BYTES);
    cudaMalloc((void **) &gpu_calc_thread, ARRAY_SIZE_IN_BYTES);

    what_is_my_id << < num_blocks, num_threads >> > (gpu_block, gpu_thread, gpu_warp, gpu_calc_thread);
    cudaMemcpy(cpu_block, gpu_block, ARRAY_SIZE_IN_BYTES, cudaMemcpyDeviceToHost);

    cudaMemcpy(cpu_thread, gpu_thread, ARRAY_SIZE_IN_BYTES, cudaMemcpyDeviceToHost);

    cudaMemcpy(cpu_warp, gpu_warp, ARRAY_SIZE_IN_BYTES, cudaMemcpyDeviceToHost);
    cudaMemcpy(cpu_calc_thread, gpu_calc_thread, ARRAY_SIZE_IN_BYTES, cudaMemcpyDeviceToHost);

    cudaFree(gpu_block);
    cudaFree(gpu_thread);
    cudaFree(gpu_warp);
    cudaFree(gpu_calc_thread);

    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        printf("cal_thread: %3d, block: %2u,wrap：%2u,thread:%3u\n",
               cpu_calc_thread[i],cpu_block[i],cpu_warp[i],cpu_thread[i]);
    }
    /*
     * 1，线程块按照编号紧密排列，
     * 2，线程索引是0-127
     * 3，一共有2块线程，
     * 4，每个线程块包含64个线程
     * 5，每个线程块的内部索引是0-63
     * */

}