#include <all.h>
#include <zconf.h>

using namespace std;

/*
 * 用传递引用代替传值
 * */
class Person
{
public:
    Person()
    { printf("person() \n"); };

    virtual ~Person()
    { printf("~person() \n"); };
private:
    string name = "name", address = "address";
};

class Student : public Person
{
public:
    Student()
    { printf("student() \n"); }

    ~Student()
    { printf("~student() \n"); };
private:
    string schoolName = "schoolname", schoolAddress = "schooladdress";
};


bool validateStudent(Student s)
{
    printf("--call valid  by value ...--\n");
    return 1;
};           // function taking a Student by value

bool validateStudent2(const Student &s)
{
    printf("call valid2 by ref ...\n");
    return 1;
};


void f20()
{
    Student plato;
    bool platoIsOK = validateStudent(plato);
/*
在调用validateStudent()时进行了6个函数调用：
Person的拷贝构造函数，为什么Student的拷贝构造一定要调用Person的拷贝构造请参见：Item 12：完整地拷贝对象
Student的拷贝构造函数,name, address, schoolName, schoolAddress的拷贝构造函数
 * */
    printf("\n");
    sleep(1);
    bool platoIsOK2 = validateStudent2(plato);
/*
 * 首先以引用的方式传递，不会构造新的对象，避免了上述例子中6个构造函数的调用。
 * 同时const也是必须的：传值的方式保证了该函数调用不会改变原来的Student，
 * 而传递引用后为了达到同样的效果，需要使用const声明来声明这一点，让编译器去进行检查！
 * */
}


class Window
{
public:
    string name() const
    { return string("win name"); }

    virtual void display() const
    {};
};

class WindowsBars : public Window
{
public:
    virtual void display() const
    {};
};

void printwindow(Window w)
{
    cout << w.name();
    w.display();
}

void printwindow2(const Window &w)
{
    cout << w.name();
    w.display();
}

void f200()
{
    WindowsBars wwbar;
    //printwindow(wwbar);//不正确，只调用基类构造函数，子类部分被截断了
    printwindow2(wwbar);
}

int main()
{


    f20();
   // f200();
    return 0;
}