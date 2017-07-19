
// atomic::compare_exchange_weak example:
#include <iostream>       // std::cout
#include <atomic>         // std::atomic
#include <thread>         // std::thread
#include <vector>         // std::vector

// a simple global linked list:
struct Node { int value; Node* next; };
std::atomic<Node*> list_head (nullptr);

void append (int val) {     // append an element to the list
    Node* oldHead = list_head;
    Node* newNode = new Node {val,oldHead};

    // what follows is equivalent to: list_head = newNode, but in a thread-safe way:
    while (!list_head.compare_exchange_weak(oldHead,newNode))
        newNode->next = oldHead;
}

//线程安全的无锁链表，但是链表顺序无法保证。
int main ()
{
    // spawn 10 threads to fill the linked list:
    std::vector<std::thread> threads;
    for (int i=0; i<10; ++i) threads.push_back(std::thread(append,i));
    for (auto& th : threads) th.join();

    // print contents:
    for (Node* it = list_head; it!=nullptr; it=it->next)
        std::cout << ' ' << it->value;
    std::cout << '\n';

    // cleanup:
    Node* it; while (it=list_head) {list_head=it->next; delete it;}

    return 0;
}

/*
原子性加减通常是用CAS(Compare and Swap)完成的，与平台相关。CAS的基本形式是：CAS(addr,old,new),
bool compare_exchange_weak (T& expected, T val,
           memory_order sync = memory_order_seq_cst) volatile noexcept;
    当addr中存放的值等于old时，用new对其替换.当前值与期望值相等时，修改当前值为设定值，返回true
    当前值与期望值不等时，将期望值修改为当前值，返回false
这个函数可能在满足true的情况下仍然返回false，所以只能在循环里使用，否则可以使用它的strong版本
 */

/*
不过我觉得那个strong版本（compare_exchange_weak）应用场景的意义似乎不大，因为是一次执行，可以完全用atomic_flag的testandset操作代替。
而这个weak版本考虑到了硬件性能的最优化，在使用CAS时一般都只会用到它。
相比无锁链表或者无锁队列，更一般的用法应该是这样的：

1 auto max_val = getMaxValue();//获取值上界
2 auto now_val = getValue();//获取当前值
3 auto exp_val = now_val; //期望值为当前值
4 do {
5   if(exp_val == max_val) break; //到达上界退出循环
6 } while(!now_val.compare_exchange_weak(exp_val, exp_val + 1))//从第2行到第5行代码可能被其他线程中断改变now_val的值
这段代码简要地说明了这个函数的使用方法，首先你要持有一个now_val，接着在企图修改这个值时，用CAS函数来判断这个值是否发生了改变，如果未改变则执行加1，若改变了则期望值随之改变为该当前值，直到循环判断到期望值与当前值相等，再执行加1操作。
可能你会觉得这不就是原子加1，用atomic自带的加法重载不就实现了。其实这里还有一个用处，也就是对期望值（或当前值）进行判断，比如当到达一个临界值以后就停止累加，原子加法没法将加1之后的判断也绑定到同一个原子操作中，也就没法实现这一点。而CAS的循环体中则可以实现一个“准改判断”——不满足条件就不允许修改当前值。

打个不恰当的比方，就像一个备胎等待老司机换胎，想着“下一个就轮到自己了”，结果发现下一个是别人，于是又想“下一个就是自己了”，“下一个就是自己了”...到最后橡胶老化被司机扔了...XD
*/