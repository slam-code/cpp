#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
        int y;
        int z;
    };
    extern __cuda_fake_struct blockDim;
    extern __cuda_fake_struct threadIdx;
    extern __cuda_fake_struct blockIdx;
    extern __cuda_fake_struct gridDim;
    #define void cudaMemcpy(void *dst, const void *src, size_t count, enum cudaMemcpyKind kind)
    #define  void cudaMalloc(void **devPtr, size_t size)
    #define warpSize
    #define cudaFree void cudaFree(void *devPtr)

    #define cudaMemcpyDeviceToHost
    //#define  dim3 struct dim3{int x;int y;int z ;}dim3;
    extern __cuda_fake_struct dim3;
#endif

__global__ void what_is_my_id_2D_A(unsigned int *const block_x,
                                   unsigned int *const block_y,
                                   unsigned int *const thread,
                                   unsigned int *const calc_thread,
                                   unsigned int *const x_thread,
                                   unsigned int *const y_thread,
                                   unsigned int *const grid_dimx,
                                   unsigned int *const block_dimx,
                                   unsigned int *const grid_dimy,
                                   unsigned int *const block_dimy
)
{
    /*
     *threadIdx.x; 某一具体线程在线程块x方向上的位置,x方向的偏移。
     *threadIdx.y;
     * blockIdx.x:线程块在线程网格的x方向的索引。
     * blockIdx.y;线程块在线程网格的y方向的索引。
     *
     *blockDim.x;线程块的宽度,x方向的【线程】数量
     *blockDim.y;线程块的高度,y方向的【线程】数量
     * gridDim.x; 线程网格的宽度,x维度上【线程块】的数量
     * gridDim.y; 线程网格的高度,y维度上【线程块】的数量
     * */

    const unsigned int idx=(blockIdx.x*blockDim.x)+threadIdx.x;
    const unsigned  int idy=(blockIdx.y*blockDim.y)*threadIdx.y;

    //找出当前的行索引，乘以每一行的线程数，最后加上在x方向上的偏移。便是相对于整个线程网格的绝对线程索引。
    const unsigned int thread_idx=((gridDim.x*blockDim.x)*idy)+idx;
    block_x[thread_idx]=blockIdx.x;//线程在线程块的x方向的偏移
    block_y[thread_idx]=blockIdx.y;//线程在线程块的y方向的偏移

    thread[thread_idx]=threadIdx.x;//线程块x维度上的线程索引。
    calc_thread[thread_idx]=thread_idx;
    x_thread[thread_idx]=idx;
    y_thread[thread_idx]=idy;
    grid_dimx[thread_idx]=gridDim.x;   //线程网格x维度上线程块的数量
    block_dimx[thread_idx]=blockDim.x; //一个线程块x维度上的线程数量

    grid_dimy[thread_idx]=gridDim.y;   //线程网格y维度上【线程块】的数量
    block_dimy[thread_idx]=blockDim.y;//一个线程块y维度上的【线程】数量
};

#define ARRAY_SIZE_X 32
#define ARRAY_SIZE_Y 16

#define ARRAY_SIZE_IN_BYTES ((ARRAY_SIZE_X)*(ARRAY_SIZE_Y)*sizeof(unsigned int ))

unsigned int cpu_block_x[ARRAY_SIZE_Y][ARRAY_SIZE_X];
unsigned int cpu_block_y[ARRAY_SIZE_Y][ARRAY_SIZE_X];

unsigned int cpu_thread[ARRAY_SIZE_Y][ARRAY_SIZE_X];

unsigned int cpu_warp[ARRAY_SIZE_Y][ARRAY_SIZE_X];
unsigned int cpu_calc_thread[ARRAY_SIZE_Y][ARRAY_SIZE_X];


unsigned int cpu_xthread[ARRAY_SIZE_Y][ARRAY_SIZE_X];
unsigned int cpu_ythread[ARRAY_SIZE_Y][ARRAY_SIZE_X];


unsigned int cpu_grid_dimx[ARRAY_SIZE_Y][ARRAY_SIZE_X];
unsigned int cpu_block_dimx[ARRAY_SIZE_Y][ARRAY_SIZE_X];

unsigned int cpu_grid_dimy[ARRAY_SIZE_Y][ARRAY_SIZE_X];

unsigned int cpu_block_dimy[ARRAY_SIZE_Y][ARRAY_SIZE_X];
/*
 * 写一个简短的内核程序来输出线程块，线程，线程束，线程全局标号。
 * */
int main()
{

    const dim3 thread_rect(32,4); //32*4=128个线程
    const dim3 blocks_rect(1,4);  //长方形，每个线程块的排列方式。

    //或者:
    const dim3 threads_square(16*8);//128个线程
    const dim3 blocks_square(2,2);


    unsigned int *gpu_block_x;
    unsigned int *gpu_block_y;
    unsigned int *gpu_thread;
    unsigned int *gpu_warp;
    unsigned int *gpu_calc_thread;
    unsigned int *gpu_xthread;
    unsigned int *gpu_ythread;

    unsigned int *gpu_grid_dimx;
    unsigned int *gpu_block_dimx;

    unsigned int *gpu_grid_dimy;
    unsigned int *gpu_block_dimy;

    cudaMalloc((void**)&gpu_block_x,ARRAY_SIZE_IN_BYTES);
    cudaMalloc((void**)&gpu_block_y,ARRAY_SIZE_IN_BYTES);
    cudaMalloc((void**)&gpu_thread,ARRAY_SIZE_IN_BYTES);
    cudaMalloc((void**)&gpu_calc_thread,ARRAY_SIZE_IN_BYTES);
    cudaMalloc((void**)&gpu_xthread,ARRAY_SIZE_IN_BYTES);
    cudaMalloc((void**)&gpu_ythread,ARRAY_SIZE_IN_BYTES);
    cudaMalloc((void**)&gpu_grid_dimx,ARRAY_SIZE_IN_BYTES);
    cudaMalloc((void**)&gpu_block_dimx,ARRAY_SIZE_IN_BYTES);
    cudaMalloc((void**)&gpu_grid_dimy,ARRAY_SIZE_IN_BYTES);
    cudaMalloc((void**)&gpu_block_dimy,ARRAY_SIZE_IN_BYTES);

    for (int i = 0; i < 1; ++i) //kernel:0-1
    {
        switch (i)
        {
            case 0:
            {
                what_is_my_id_2D_A<<<blocks_rect,thread_rect>>>(gpu_block_x,
                        gpu_block_y,
                        gpu_thread,
                        gpu_calc_thread,
                        gpu_xthread,
                        gpu_ythread,
                        gpu_grid_dimx,
                        gpu_block_dimx,
                        gpu_grid_dimy,
                        gpu_block_dimy
                );
            }
                break;
            case 1:
            {
                what_is_my_id_2D_A<<<blocks_rect,thread_rect>>>(gpu_block_x,
                        gpu_block_y,
                        gpu_thread,
                        gpu_calc_thread,
                        gpu_xthread,
                        gpu_ythread,
                        gpu_grid_dimx,
                        gpu_block_dimx,
                        gpu_grid_dimy,
                        gpu_block_dimy
                );
            }
            default:
                exit(1);
                break;
        }

        cudaMemcpy(cpu_block_x,gpu_block_x,ARRAY_SIZE_IN_BYTES,cudaMemcpyDeviceToHost);
        cudaMemcpy(cpu_block_y,gpu_block_y,ARRAY_SIZE_IN_BYTES,cudaMemcpyDeviceToHost);
        cudaMemcpy(cpu_thread,gpu_thread,ARRAY_SIZE_IN_BYTES,cudaMemcpyDeviceToHost);
        cudaMemcpy(cpu_calc_thread,gpu_calc_thread,ARRAY_SIZE_IN_BYTES,cudaMemcpyDeviceToHost);
        cudaMemcpy(cpu_xthread,gpu_xthread,ARRAY_SIZE_IN_BYTES,cudaMemcpyDeviceToHost);
        cudaMemcpy(cpu_ythread,gpu_ythread,ARRAY_SIZE_IN_BYTES,cudaMemcpyDeviceToHost);
        cudaMemcpy(cpu_grid_dimx,gpu_grid_dimx,ARRAY_SIZE_IN_BYTES,cudaMemcpyDeviceToHost);
        cudaMemcpy(cpu_block_dimx,gpu_block_dimx,ARRAY_SIZE_IN_BYTES,cudaMemcpyDeviceToHost);
        cudaMemcpy(cpu_grid_dimy,gpu_grid_dimy,ARRAY_SIZE_IN_BYTES,cudaMemcpyDeviceToHost);
        cudaMemcpy(cpu_block_dimy,gpu_block_dimy,ARRAY_SIZE_IN_BYTES,cudaMemcpyDeviceToHost);
        printf("\nkernel %d\n",i);
        for (int y = 0; y < ARRAY_SIZE_Y; ++y)
        {
            for (int x = 0; x < ARRAY_SIZE_X; ++x)
            {
                printf("CT:%2u,BKX:%1u,TID：%2u,YID：%2u,XTID:%2u,GDX:%1u,BDX:%1u,GDY:%1u,BDY:%1u\n",
                       cpu_calc_thread[y][x],
                       cpu_block_x[y][x],
                       cpu_block_y[y][x],
                       cpu_thread[y][x],
                       cpu_ythread[y][x],
                       cpu_xthread[y][x],
                       cpu_grid_dimx[y][x],
                       cpu_block_dimx[y][x],
                       cpu_grid_dimy[y][x],
                       cpu_block_dimy[y][x]
                );
            }
        }
        sleep(1);
    }

}