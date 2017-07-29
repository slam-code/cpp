#include <thread>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <unistd.h>
using namespace std;
//正确用法：
condition_variable cv;
mutex a;
int i=0;

int main()
{

	thread t1([&] 
	{
		i++;
		//usleep(1000);
		cout << "notify one" << endl;
		cv.notify_one();
	});

	thread t2([&]
	{
		this_thread::sleep_for(chrono::seconds(3));
		unique_lock<mutex> g(a);
		//sleep(3);//linux:3s
		cv.wait(g,[]{return i>0; });
		cout << "received notification" << endl;
		
	});
	
	t1.join();
	t2.join();
    return 0;
}