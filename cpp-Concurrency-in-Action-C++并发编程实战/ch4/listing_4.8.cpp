template<>//std::packaged_task<>的特化——局部类定义
class packaged_task<std::string(std::vector < char>*, int)> {
public:
    template<typename Callable>
    explicit packaged_task(Callable &&f);

    std::future <std::string> get_future();

    void operator()(std::vector<char> *, int);
};
//packaged_task<>对一个函数或者可调用对象，绑定一个期望

/*使用std::async会让分割算法到各个任务中变的容易,这样程序就能并发的执行了。
 * 不过,这不是让一个std::future与一个任务实例相关联的唯一方式;你也可以将任务包装入一个std::packaged_task<>实例中,
 * 或通过编写代码的方式,使用std::promise<>类型模板显示设置值。与std::promise<> 对比,
 * std::packaged_task<>具有更高层的抽象,所以我们从“高抽象”的模板说起。*/




/*
 * 	std::packaged_task<>对一个函数或可调用对象,绑定一个期望。当 std::packaged_task<>对象被调用,
 * 	它就会调用相关函数或可调用对象,将期望状态置为就绪,返回值也会被存储为相关数据。
 * 	这可以用在构建线程池的建筑块(可见第9章),或用于其他任务的管理,比如在任务所在线程上运行任务,
 * 	或将它们顺序的运行在一个特殊的后台线程上。当一个粒度较大的操作可以被分解为独立的子任务时,
 * 	其中每个子任务就可以包含在一个std::packaged_task<>实例中,之后这个实例将传递到任务调度器或线程池中。
 * 	这就是对任务的细节进行抽象了;调度器仅处理std::packaged_task<>	实例,要比处理独立的函数高效的多。

 std::packaged_task<>的模板参数是一个函数签名,比如void()就是一个没有参数也没有返回值的函数,
 或int(std::string&,	double*)就是有一个非const引用的std::string和一个指向double类型的指针,
 并且返回类型是int。当你构造出一个std::packaged_task<>实例时,你必须传入一个函数或可调用对象,
 这个函数或可调用的对象需要能接收指定的参数和返回可转换为指定返回类型的值。
 类型可以不完全匹配;你可以用一个int类型的参数和返回一个float类型的函数,
 来构建std::packaged_task<double(double)> 的实例,因为在这里,类型可以隐式转换。
 指定函数签名的返回类型可以用来标识,从get_future()返回的std::future<>的类型,不过函数签名的参数列表,
 可用来指定“打包任务”的函数调用操作符。
 例如,局部类定义std::packaged_task<std::string(std::vector<char>*,int)>
 将在下面的代码清代中使用。

 * */