#include <condition_variable>
#include <mutex>
#include <chrono>
#include <iostream>
std::condition_variable cv;
bool done= false;
std::mutex m;
bool wait_loop()
{
    auto const timeout= std::chrono::steady_clock::now()+
        std::chrono::milliseconds(500);
    std::unique_lock<std::mutex> lk(m);
    while(!done)
    {
        if(cv.wait_until(lk,timeout)==std::cv_status::timeout)
            break;
    }
    return done;
}


int main()
{
    done= true;
    wait_loop();
    std::cout<<"(int)std::cv_status::no_timeout:"<<(int)std::cv_status::no_timeout<<std::endl;
    std::cout<<"(int)std::cv_status::timeout:"<<(int)std::cv_status::timeout<<std::endl;
}