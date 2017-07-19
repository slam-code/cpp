#pragma once

#include <string>
#include <map>
#include <sstream>

namespace cpplask {

class response_t {
    unsigned int m_code;
    std::string m_status;
    std::string m_mime_type;

    std::stringstream m_buffer;
public:
    response_t() : m_code(200), m_status("OK"), m_mime_type("text/html"), m_buffer() { }
    unsigned int& code() { return m_code; }
    template<typename T>
    std::stringstream& operator<<(T value) {
        m_buffer << value;
        return m_buffer;
    }
    void write(char* buffer, int count) {
        m_buffer.write(buffer, count);
    }
    std::string str() {
        return m_buffer.str();
    }
    std::string& status() {
        return m_status;
    }
};

}
