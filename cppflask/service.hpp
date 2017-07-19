#pragma once
#include <url_scanner.hpp>
#include <response.hpp>
#include <request.hpp>

#include <string>
#include <iostream>
#include <functional>
#include <vector>
#include <memory>
#include <sstream>
#include <fstream>
#include <map>

namespace cpplask {
bool serve_static_file(request_t& req, path_t path);

class route_t {
protected:
    route_t() { };
    virtual ~route_t() { };
public:
    virtual bool operator()(request_t& path) = 0;
};

template<typename... PARAMS>
class route_impl_t : public route_t {
    std::string m_pattern;
    std::function<void(request_t&, PARAMS...)> m_f;

public:
    route_impl_t(std::string pattern) : m_pattern(pattern), m_f() {
    }
    template<typename LAMDA>
    route_impl_t<PARAMS...>& operator=(LAMDA f) {
        // this assignment fails if f doesn't match the params passed in, which is good
        m_f = f;
        return *this;
    }
    bool operator()(request_t& req) {
        std::function<void(PARAMS...)> wrapped_func = [&](PARAMS... params) { m_f(req, params...); };
        return url_scan(m_pattern, req.path(), wrapped_func);
    }
};

template <typename... PARAMS>
class route_proxy_t {
    typedef std::shared_ptr<route_impl_t<PARAMS...>> route_sptr;  
    route_sptr m_route;
public:
    route_proxy_t(route_sptr route) : m_route(route) { }
    template<typename LAMDA>
    route_proxy_t<PARAMS...>& operator=(LAMDA route) {
        m_route->operator=(route);
        return *this;
    }
    route_proxy_t<PARAMS...>& operator=(route_proxy_t other_proxy) = delete; 
};

class service_t {

    std::vector<std::shared_ptr<route_t>> m_routes;
public:
    service_t() : m_routes() { }
    template<typename... PARAMS>
    route_proxy_t<PARAMS...> map(std::string pattern) {
        std::shared_ptr<route_impl_t<PARAMS...>> route = std::make_shared<route_impl_t<PARAMS...>>(pattern);
        m_routes.push_back(route);
        return route_proxy_t<PARAMS...>(route);
    }

    request_t& serve(request_t& req) {
        bool found = false;
        for (auto& r : m_routes) {
            if (r->operator()(req)) {
                found = true;
                break;
            }
        }
        if (found) {

        }
        else {
            req.response().code() = 404; 
            req.response().status() = "Resource not found"; 
        }
        return req;

    }
};

}
