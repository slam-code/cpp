#include <thread>
#include <condition_variable>
#include <iostream>
#include <mutex>
using namespace std;
//错误用法：
int main()
{
	condition_variable cv;
	mutex a;
	thread t1([&] 
	{
		
		cout << "notify one" << endl;
		cv.notify_one();
	});
	thread t2([&]
	{
		//this_thread::sleep_for(chrono::milliseconds(100));
		unique_lock<mutex> g(a);
		cv.wait(g);
		cout << "received notification" << endl;
		
	});
	t1.join();
	t2.join();
    return 0;
}