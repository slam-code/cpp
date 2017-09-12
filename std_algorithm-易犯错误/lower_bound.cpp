#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class timestamp
{
public:
    timestamp(int time_){
        time=time_;
    }; 
//private:
    int time;
    
};

bool  operator <(timestamp lhs ,timestamp rhs)
{
    return lhs.time<rhs.time;
}

int main()
{
    std::vector<int> data = { 1, 1, 2, 3, 3, 3, 3, 4, 4, 4, 5, 5, 6 };

    auto lower = std::lower_bound(data.begin(), data.end(), 4);
    auto upper = std::upper_bound(data.begin(), data.end(), 4);

    std::copy(lower, upper, std::ostream_iterator<int>(std::cout, " "));

    std::cout <<"\n--\n";

    

    std::vector<timestamp> 
    timedeque{timestamp(10),timestamp(20),timestamp(20),timestamp(20),timestamp(30),timestamp(30),timestamp(40),timestamp(50),timestamp(60)};

    auto start =
    std::lower_bound(timedeque.begin(), timedeque.end(), timestamp(25),
       [](const timestamp& timeindeque,//自定义lambda表达式,按照时间戳比较
          const timestamp timevalue) {
        cout<<timeindeque.time<<" ,"<<timevalue.time<<endl;
         return timeindeque  < timevalue ;

     });
    std::cout<<"start:"<<(*start).time<<std::endl;
    return 0;
}

//g++ l349.cpp  -std=c++11 -w