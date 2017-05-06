template<>
class packaged_task<std::string(std::vector < char > *, int)> {
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