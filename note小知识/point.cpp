#include <iostream>
#include <stdio.h>
using namespace std;
int change(char* name){  
    cout<<"before " ;  
    cout<<" name= " <<name;  
    cout<<" &name=" <<&name<<endl;  
    name="alter";  
    cout<<"after ";  
    cout<<"name=" <<name;  
    cout<<" &name=" <<&name<<endl;  
    return 1;  
}  

int change2(char** name){  
    cout<<"before " ;  
    cout<<" name= " <<name;  
    cout<<" &name=" <<&name<<endl;  
    *name="alter";  
    cout<<"after ";  
    cout<<"name=" <<name;  
    cout<<" &name=" <<&name<<endl;  
    return 1;  
}  

int change4(int & name){  
    cout<<"before " ;  
    cout<<" name= " <<name;  
    cout<<" &name=" <<&name<<endl;  
    name=3;  
    cout<<"after ";  
    cout<<"name=" <<name;  
    cout<<" &name=" <<&name<<endl;  
    return 5;  
}  
int main()  
{  
    char *str = "this is a test";  
  
    cout<<"main before ";  
    cout<<"str=" <<str ;  
    cout<<" &str=" <<&str<<endl<<endl;  

    change(str);  
    cout<<"main after ";  
    cout<<"str=" <<str;  
    cout<<" &str=" <<&str<<endl<<endl;  

    change2(&str);  
    cout.width(10); 
    cout<<"main after ";  
    cout<<"str=" <<str;  
    cout<<" &str=" <<&str<<endl<<endl; 

    int i=0; 
    change4(i);  
   // cout.width(10); 
   // cout<<"main after ";  
   // cout<<"str=" <<str;  
   // cout<<" &str=" <<&str<<endl<<endl; 
    return 1;  
}  