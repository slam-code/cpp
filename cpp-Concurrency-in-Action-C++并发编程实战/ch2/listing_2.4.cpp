#include <thread>
#include <string>

void open_document_and_display_gui(std::string const &filename)
{}

bool done_editing()
{
    return true;
}

enum command_type
{
    open_new_document
};


struct user_command
{
    command_type type;

    user_command() :
            type(open_new_document)
    {}
};

user_command get_user_input()
{
    return user_command();
}

std::string get_filename_from_user()
{
    return "foo.doc";
}

void process_user_input(user_command const &cmd)
{}

void edit_document(std::string const &filename)
{
    open_document_and_display_gui(filename);
    while (!done_editing())
    {
        user_command cmd = get_user_input();
        if (cmd.type == open_new_document)
        {
            std::string const new_name = get_filename_from_user();
            std::thread t(edit_document, new_name);//实参要拷贝到每个线程的独立内存中
            t.detach();
        } else
        {
            process_user_input(cmd);
        }
    }
}

int main()
{
    edit_document("bar.doc");
}
/*如果不想等待线程结束,可以分离(detaching)线程,从而避免异常安全(exception-safety)问题。
 不过,这就打破了线程与 std::thread	 对象的联系,即使线程仍然在后台运行着,分离操作也能确保
 std::terminate()在 	std::thread	 对象销毁之后才被调用。

使用detach()会让线程在后台运行,这就意味着主线程不能与之产生直接交互。也就是说,不
会等待这个线程结束;如果线程分离,那么就不可能有 	std::thread	 对象能引用它,分离线程
的确在后台运行,所以分离线程不能被加入。不过C++运行库保证,当线程退出时,相关资源
的能够正确回收,后台线程的归属和控制C++运行库都会处理。
 */