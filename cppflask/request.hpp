#pragma once

#include <string>
#include <map>

namespace cpplask {

class request_t {
    std::string m_path;
    response_t m_response;
    std::map<std::string, std::string> m_headers;

public:
    request_t(const std::string& path, std::map<std::string, std::string>&& headers) : m_path(path), m_response(), m_headers(headers) { }
    request_t(std::string path, std::map<std::string, std::string> headers) : m_path(path), m_response(), m_headers(headers) { }
    const std::string& path() { return m_path; }
    response_t& response() { return m_response; }
    std::string headers(std::string name) { return m_headers[name]; }
};

}
