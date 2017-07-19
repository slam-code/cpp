//
// Created by shen on 16-9-19.
//

#ifndef EFFECTIVECPP_CH14_H
#define EFFECTIVECPP_CH14_H

#include <zconf.h>
#include <pthread.h>
#include "ch6.h"
#define  Mutex pthread_mutex_t
#define lock pthread_mutex_lock
#define unlock pthread_mutex_unlock

class Lock:private ch6::Uncopyable {
public:
    explicit Lock(Mutex* pm):mutexPtr(pm){
        lock(mutexPtr); };
    ~Lock(){
        unlock(mutexPtr);}
private:
    Mutex *mutexPtr;
};

void f14(){
    Mutex m;
    //Lock m1(&m);//禁止复制

}
#endif //EFFECTIVECPP_CH14_H
