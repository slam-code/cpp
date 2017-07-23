#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <thread>
#include <cassert>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

void hello(const string& s){
    cout << s << endl;
}

struct String{
    string s;

    String(const string& s):s(s){}
    String(const char* s):s(s){}

    void sub(int pos){
        s = s.substr(pos);
    }

    void half(){
        s = s.substr(0, s.length()/2);
    }

    friend ostream& operator << (ostream& out, const String& str){
        return out << str.s;
    }
};

int main(){
    vector<String> strs{"helloworld", "123321", "http"};

    for_each(strs.begin(), strs.end(), mem_fn(&String::half));
    for(auto& str : strs){
        cout << str << endl;
    }

    cout << endl;

    // 需要有参数传递的时候可以用 bind
    for_each(strs.begin(), strs.end(), bind(&String::sub, _1, 1));
    for(auto& str : strs){
        cout << str << endl;
    }

    return 0;
}

