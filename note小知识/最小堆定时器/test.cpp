#include <csignal>
#include <ares_build.h>
#include "heap_timer.h"
#include "time_heap.h"
#include "tepoll_wait.h"

int main() {

    while (!stop_server) {
        number = tepoll_wait(epollfd, events, MAX_EVENT_NUMBER);
        for (i = 0; i < number; i++) {
            int fd = events[i].data.fd;
            if ((events[i].events & EPOLLIN) && (fd == uart_fd)) {
                //读取用户数据
                if ((timer_id = find_exist_timer(ip_address)) != -1) {
                    //add to the exist timer
                    heap_timer **heap_array = heap.get_heap_array();
                    heap_array[timer_id]->user_data->add_target(RSSI, target_id);
                    continue;
                }

                heap_timer *timer = new heap_timer(200);
                timer->cb_func = cb_func;
                timer->user_data = new client_data(ip_address);
                timer->user_data->add_target(RSSI, target_id);
                heap.add_timer(timer);
            } else if ((fd == pipefd[0]) && (events[i].events & EPOLLIN)) {
                //此处进行了统一信号源处理，通过双向管道来获取SIGTERM以及SIGINT的信号，在主循环中进行统一处理
                ret = recv(pipefd[0], signals, sizeof(signals), 0);
                if (ret == -1) {
                    continue;
                } else if (ret == 0) {
                    continue;
                } else {
                    for (int i = 0; i < ret; ++i) {
                        switch (signals[i]) {
                            case SIGTERM:
                            case SIGINT: {
                                stop_server = true;
                            }

                        }
                    }
                }
            }
        }
    }
}
