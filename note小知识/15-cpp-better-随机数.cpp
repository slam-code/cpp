
#include <iostream>
#include <vector>
#include <random>

using namespace std;
std::mt19937 rng(42);//随机数种子
std::uniform_real_distribution<float> rand_distribution(0.0, 1);
//[0,1],概率均匀分布

std::uniform_real_distribution<float> rand2_distribution(-1.f, 1.f);
//[-1 ,1]
void getnum()
{

    for (int i = 0; i != 100; ++i) {
        const float angle = rand_distribution(rng); 
        cout<< angle<<endl;
    }

};

int main()
{
    //srand(0);
    //cout.precision(3);
     getnum();
}