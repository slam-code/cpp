#pragma once

#include <service.hpp>

namespace cpplask {

/** Really simple single threaded server in POSIX and C++11. For development only, not for production use */
void basic_serve(cpplask::service_t& service, uint32_t port);

}
