void fun()
{
    cout<<”hello word”<<endl;
}

int main()
{
         timer t; //开始计时
         fun()
         cout<<t.elapsed()<<endl; //打印fun函数耗时多少毫秒
cout<<t.elapsed_micro ()<<endl; //打印微秒
cout<<t.elapsed_nano ()<<endl; //打印纳秒
cout<<t.elapsed_seconds()<<endl; //打印秒
cout<<t.elapsed_minutes()<<endl; //打印分钟
cout<<t.elapsed_hours()<<endl; //打印小时
}