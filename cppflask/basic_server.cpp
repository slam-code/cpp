#include <basic_server.hpp>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <csignal>

#include <map>
#include <vector>
#include <sstream>
#include <atomic>
#include <thread>
#include <algorithm>

namespace cpplask {

namespace
{
    std::atomic<bool> g_keep_going;
}

extern "C" {
    static void signal_handler(int)
    {
        std::cerr << "SIGINT received" << std::endl;
        g_keep_going = false; 
    }
}

sigset_t stop_signals() {
    sigset_t set;
    sigset_t orig_set;
    sigfillset(&set);
    pthread_sigmask(SIG_SETMASK, &set, &orig_set);
    return orig_set;
}

void restore_signals(sigset_t& signals) {
    pthread_sigmask(SIG_SETMASK, &signals, NULL);
}

struct listen_socket {
    int listen_socket_fd;
    listen_socket(uint32_t port) : 
        listen_socket_fd(-1) {

        sockaddr_in server_address;

        try {
            listen_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
            if (listen_socket_fd < 0) {
                throw std::runtime_error("error during socket opening");
            }

            bzero(reinterpret_cast<char*>(&server_address), sizeof(server_address));

            server_address.sin_family = AF_INET;
            server_address.sin_addr.s_addr = INADDR_ANY;
            server_address.sin_port = htons(port);

            if (bind(listen_socket_fd, reinterpret_cast<struct sockaddr*>(&server_address), sizeof(server_address)) < 0) {
                throw std::runtime_error(std::string("Error during socket binding: ") + strerror(errno));
            }
        }
        catch (...) {
            if (listen_socket_fd >= 0) {
                close(listen_socket_fd);
            }
            throw;
        }
    }
    void serve(cpplask::service_t& service);
    ~listen_socket() {
        close(listen_socket_fd);
    }
};


struct client_socket {
    int socket_fd;
    bool request_complete;
    std::string buffer;
    cpplask::service_t* service;
    client_socket(int fd, cpplask::service_t& serv) : socket_fd(fd), request_complete(false), buffer(), service(&serv) {
    }

    client_socket(const client_socket&) = delete;
    client_socket(client_socket&& c) : socket_fd(-1), request_complete(false), buffer(), service(nullptr) {
        swap(c);
    }
    client_socket& operator=(const client_socket&) = delete;
    client_socket& operator=(client_socket&& c) {
        swap(c);
        return *this;
    }

    void swap(client_socket& c) {
        std::swap(socket_fd,c.socket_fd);
        std::swap(request_complete, c.request_complete);
        std::swap(buffer,c.buffer);
        std::swap(service,c.service);
    }

    void add_fds(fd_set& rfds, fd_set& wfds, fd_set& xfds) {
        if (request_complete) {
            FD_SET(socket_fd, &wfds);
        }
        else {
            FD_SET(socket_fd, &rfds);
        }
        FD_SET(socket_fd, &xfds);
    }
    void ingest(const std::string& data);
    ~client_socket() {
        if (socket_fd >= 0) {
            close(socket_fd);
        }
    }
};

auto parse_request(std::string bufferstr) -> auto {
    char* buffer = const_cast<char*>(bufferstr.c_str());

    char* strtok_state;
    char* current_line_buf = 0;

    std::string verb = strtok_r(buffer, " ", &strtok_state);
    std::string path = strtok_r(NULL, " ", &strtok_state);
    std::map<std::string, std::string> query_params;

    std::string version = strtok_r(NULL, "\n", &strtok_state);
    std::map<std::string, std::string> headers;
    do {
        current_line_buf = strtok_r(NULL, "\n", &strtok_state);
        const std::string current_line(current_line_buf);
        size_t index_of_colon = current_line.find(":"); 
        if (index_of_colon != std::string::npos) {
            const std::string name = current_line.substr(0, index_of_colon);
            const std::string value = current_line.substr(index_of_colon+2, current_line.length()-index_of_colon-3);
            headers[name] = value;
        }
    } while (strlen(current_line_buf) > 1);
    std::cerr << verb << " " << path << "\n";

    return std::make_pair(path, headers); 
}

void client_socket::ingest(const std::string& data) {
    buffer += data;
    std::string marker = "\r\n\r\n";

    if (std::search(buffer.begin(), buffer.end(), marker.begin(), marker.end()) != buffer.end()) {

        auto parameters = parse_request(buffer);
        cpplask::request_t req(std::get<0>(parameters), std::get<1>(parameters));
        service->serve(req);

        std::string message = req.response().str();

        std::stringstream ss;
        ss << "HTTP/1.1 " << req.response().code() << " " << req.response().status() << "\n";
        ss << "Content-Type: text/plain\n";
        ss << "Content-length: " << message.size() << "\n\n";
        ss << message;

        buffer = ss.str();
        request_complete = true;
    }
}

void basic_serve(cpplask::service_t& service, uint32_t port) {
    g_keep_going=true;
    listen_socket listen_socket(port);
    std::cerr << "listening on port " << port << std::endl;
    auto orig = stop_signals();
    listen_socket.serve(service);
    restore_signals(orig);
    std::cerr << "Exiting" << std::endl;
}



//FIXME function far too long, REFACTOR!
void listen_socket::serve(cpplask::service_t& service) {

    struct sigaction new_action;
    sigemptyset (&new_action.sa_mask);
    new_action.sa_flags = 0;
    new_action.sa_handler = signal_handler;
    sigaction(SIGINT, &new_action, NULL);
    sigaction(SIGQUIT, &new_action, NULL);
    sigaction(SIGTERM, &new_action, NULL);

    std::vector<client_socket> clients;

    while (g_keep_going) {
        listen(listen_socket_fd,50);

        fd_set rfds, wfds, xfds;

        FD_ZERO(&rfds);
        FD_ZERO(&wfds);
        FD_ZERO(&xfds);

        FD_SET(listen_socket_fd, &rfds);
        int max_fd = listen_socket_fd;

        for (auto&& client : clients) {
            client.add_fds(rfds, wfds, xfds);
            max_fd = std::max(max_fd, client.socket_fd);
        }

        sigset_t mask;
        sigemptyset (&mask);

        int pselect_rtn = pselect(max_fd+1, &rfds, &wfds, &xfds, NULL, &mask);
        if (pselect_rtn < 0) {
            perror("pselect");
        }
        if (!g_keep_going) {
            break;
        }
        if (pselect_rtn > 0 && FD_ISSET(listen_socket_fd, &rfds)) {
            // new client connecting    
            std::cerr << "client connected" << std::endl;
            sockaddr_in client_address;
            socklen_t client_address_len = sizeof(client_address);

            int accept_socket_fd = accept(listen_socket_fd, 
                     reinterpret_cast<struct sockaddr*>(&client_address), 
                     &client_address_len);
            if (accept_socket_fd < 0) {
                throw std::runtime_error("Error during accept");
            }
            clients.emplace_back(accept_socket_fd, service);
        }


        for (auto& client : clients) {
            int& accept_socket_fd = client.socket_fd;
            
            if (FD_ISSET(accept_socket_fd, &rfds)) {

                char buffer[2048] = {0};
                int num_read = read(accept_socket_fd,buffer,2040);
                if (num_read < 0) {
                    throw std::runtime_error(std::string("ERROR reading from socket:") + std::to_string(accept_socket_fd) + strerror(errno));
                }

                client.ingest(std::string(buffer, num_read));
            }
        }

        clients.erase(std::remove_if(clients.begin(), clients.end(), [&](auto&& client) {
            int& write_socket_fd = client.socket_fd;
            std::string& buffstr = client.buffer;
            
            if (FD_ISSET(write_socket_fd, &wfds)) {
                int total_written = 0;
                ssize_t num_written = 0;

                do {
                    //FIXME MSG_NOSIGNAL is a bit hacky
                    //FIXME is writing 1200 at a time really a good idea?
                    num_written = send(write_socket_fd,buffstr.c_str(),std::min(static_cast<size_t>(1200), buffstr.size()), MSG_DONTWAIT| MSG_NOSIGNAL);
                    std::cerr << "Written " << num_written << " of " << buffstr.size() << std::endl;

                    if (num_written < 0) {
                        if (errno == EWOULDBLOCK || errno == EAGAIN) {
                            total_written += num_written;
                            buffstr = std::string(buffstr.begin() + num_written, buffstr.end());
                            return false;
                        }
                        else {
                            return true;
                        }
                    }
                    else if (num_written == static_cast<ssize_t>(buffstr.size())) {
                        return true;
                    }
                    else {
                        total_written += num_written;
                        buffstr = std::string(buffstr.begin() + num_written, buffstr.end());
                    }
                } while (num_written > 0);


                return false;

            }
            else {
                return false;
            }
        }), clients.end());



        clients.erase(std::remove_if(clients.begin(), clients.end(), [&](auto&& client) {
            return (FD_ISSET(client.socket_fd, &xfds));
        }), clients.end());
    }
} 

}
