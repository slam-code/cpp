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

bool serve_static_file(request_t& req, path_t path) {

    // This feels like it could be safer...
    if (path.str.find("..") != std::string::npos) {
        req.response().code() = 403;
        req.response().status() = "Forbidden";
    
    }
    std::fstream file(path.str, std::ios::in);

    char buffer[1024];

    do {
        file.read(buffer, 1024);
        req.response().write(buffer, file.gcount());

    } while (!file.eof());


    file.close();
    return true;
}
}
