
#include <iostream>
#include <iterator>
#include <vector>
 
int main() 
{
    std::vector<int> v{ 3, 1, 4 };
    std::cout << "distance(first, last) = "
              << std::distance(v.begin(), v.end()) << '\n'
              << "distance(last, first) = "
              << std::distance(v.end(), v.begin()) << '\n';
}
/*
distance(first, last) = 3
distance(last, first) = -3
*/