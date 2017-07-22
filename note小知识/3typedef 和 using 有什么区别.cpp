//https://www.zhihu.com/question/25102205
//定义模板的别名，只能使用using。
//Example:
using handler_t = void (*)(int);
extern handler_t ignore; 
extern void (*ignore)(int); // redeclare ignore 
using cell = pair<void*, cell*>; // ill-formed


#include <iostream>
template<typename T>
class A
{
public:
A()
{
std::cout << "A " << typeid(T).name() << std::endl;
}
};
template <typename T>
using B = A<T>;
template <typename T>
typedef A<T> C;
int main()
{
A<int> a;
B<int> b; // OK, B is an alias of class A.
C<int> c; // Syntax Error, C cannot be recognized as a type.
return 0;
}


std::unique_ptr<std::unordered_map<std::string, std::string>>//，所以我们就很容易想到使用类型别名typedef:
typedef std::unique_ptr<std::unordered_map<std::string, std::string>> UPtrMapSS;

//而如Meyers写道，这个写法太过C++98，我们在C++11有新的写法：

using UPtrMapSS = std::unique_ptr<std::unordered_map<std::string, std::string>>;


//或许从这个例子中，我们是看不出来明显的好处的（而于我来说，以一个第三者的角度，这个例子也难以说服我一定要用C++11的using）。于是，Meyers也开始来举例阐述使用using的好处，他举的第一个例子就是函数指针：

typedef void (*FP) (int, const std::string&);
//若不是特别熟悉函数指针与typedef的童鞋，我相信第一眼还是很难指出FP其实是一个别名，代表着的是一个函数指针，而指向的这个函数返回类型是void，接受参数是int, const std::string&。那么，让我们换做C++11的写法：

using FP = void (*) (int, const std::string&);
//我想，即使第一次读到这样代码，并且知道C++11 using的童鞋也能很容易知道FP是一个别名，using的写法把别名的名字强制分离到了左边，而把别名指向的放在了右边，比较清晰。

//而针对这样的例子，我想我可以再补充一个例子：

typedef std::string (Foo::* fooMemFnPtr) (const std::string&);

using fooMemFnPtr = std::string (Foo::*) (const std::string&);
//从可读性来看，using也是要好于typedef的。

//那么，若是从可读性的理由支持using，力度也是稍微不足的。于是，在P64开始，Meyers祭出了第二个理由，那就是举出了一个typedef做不到，而using可以做到的例子：alias templates, 模板别名。

template <typename T>
using Vec = MyVector<T, MyAlloc<T>>;

// usage
Vec<int> vec;
//这一切都会非常的自然。

//那么，若你使用typedef来做这一切：

template <typename T>
typedef MyVector<T, MyAlloc<T>> Vec;

// usage
Vec<int> vec;
//当你使用编译器编译的时候，将会得到类似：error: a typedef cannot be a template的错误信息。

//那么，为什么typedef不可以呢？在 n1449 中提到过这样的话："we specifically avoid the term “typedef template” and introduce the new syntax involving the pair “using” and “=” to help avoid confusion: we are not defining any types here, we are introducing a synonym (i.e. alias) for an abstraction of a type-id (i.e. type expression) involving template parameters." 所以，我认为这其实是标准委员会他们的观点与选择，在C++11中，也是完全鼓励用using，而不用typedef的。

//那么，如果我们想要用typedef做到这一点，应该怎么办呢？如Meyers所述以及一些STL的做法，那就是包装一层，如:

template <typename T>
struct Vec
{
  typedef MyVector<T, MyAlloc<T>> type;
};

// usage
Vec<int>::type vec;
//正如你所看到的，这样是非常不漂亮的。而更糟糕的是，如果你想要把这样的类型用在模板类或者进行参数传递的时候，你需要使用typename强制指定这样的成员为类型，而不是说这样的::type是一个静态成员亦或者其它情况可以满足这样的语法，如：

template <typename T>
class Widget
{
  typename Vec<T>::type vec;
};
//然而，如果是使用using语法的模板别名，你则完全避免了因为::type引起的问题，也就完全不需要typename来指定了。

// if we use using syntax.
template <typename T>
class Widget
{
  Vec<T> vec;
};
//一切都会非常的自然，所以于此，非常推荐using，而非typedef。

//而在P66开始，Meyers举例了使用using进行模板别名的标准库例子，那就是<type_traits>。在C++11中，我们可以使用type traits的方法来进行移除const, 添加引用等操作，如：

std::remove_const<T>::type  // const T -> T

std::remove_reference<T>::type // T& / T&& -> T

std::add_lvalue_reference<T>::type // T -> T&
//而这样的方式是不是很像我们之前的struct包裹typedef的例子？所以，从C++14开始，标准库提供了使用using模板别名的方法，如上面的例子可以变为:

std::remove_const_t<T>;
std::remove_reference_t<T>;
std::add_lvalue_reference_t<T>;
//而每一个方法都是在之前的基础上添加了_t。而其实现正是using模板别名：

template <typename T>
using std::remove_const_t = typename std::remove_const<T>::type;

// the rest is the same...
//那么为什么这里要加typename？这其实就和我们之前的讨论一样，在泛型编程中，::type需要让我们显示确定这是类型，而非类的静态成员或者其它满足这样语法的情况，编译器是相当“愚蠢”的。



https://zhuanlan.zhihu.com/p/21264013