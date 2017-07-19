#pragma once
#include <tuple>
#include <string>
#include <stdexcept>
#include <functional>

namespace cpplask {

template<typename...PARAMS, typename ITERATOR>
bool url_scan2(std::tuple<>, ITERATOR pattern,ITERATOR path,ITERATOR pattern_end,ITERATOR path_end, std::function<void(PARAMS...)>& f, PARAMS... params) {
    while (path != path_end && pattern != pattern_end) {
        // There maybe some text after the last %, deal with it.
        if (*path != *pattern) {
            return false;
        }
        path++;
        pattern++;
    }
    if (path != path_end || pattern != pattern_end) {
        return false;
    }
    f(params...);
    return true;
}

template <typename VALUE_TYPE>
class field_handler {
    VALUE_TYPE value;
public:
    field_handler() : value() { }
    bool try_append(char c) {
        return value.try_append(c);
    }
    int get_value() {
        return value.get_value();
    }
};

template <>
class field_handler<int> {
    std::string field;
public:
    field_handler() : field() { }
    bool try_append(char c) {
        if (!std::isdigit(c))
            return false;
        field += c;
        return true;
    }
    int get_value() {
        return std::stoi(field.c_str());
    }
};

template <>
class field_handler<std::string> {
    std::string field;
public:
    field_handler() : field() { }
    bool try_append(char c) {
        if (c == '/')
            return false;
        field += c;
        return true;
    }
    std::string get_value() {
        return field.c_str();
    }
};

struct path_t {
    path_t() : str() { }
    path_t(std::string str_in) : str(str_in) { }
    std::string str;
};

template <>
class field_handler<path_t> {
    std::string field;
public:
    field_handler() : field() { }
    bool try_append(char c) {
        field += c;
        return true;
    }
    path_t get_value() {
        return path_t (field);
    }
};


template<typename... PARAMS, typename... PARAMS_IN, typename... PARAMS_OUT, typename ITERATOR, typename VALUE>
bool url_scan2(std::tuple<VALUE,PARAMS_IN...>, ITERATOR pattern, ITERATOR path, ITERATOR pattern_end, ITERATOR path_end, std::function<void(PARAMS...)>& f, PARAMS_OUT... params) {

    // At this point we know there's at least one more % to find as the std::tuple has at least one type in it (PARAMS_IN... could be empty).
    // effectively each recursion takes the head of the tuple's types and moves it to the back of the arguments list (PARAMS_OUT).

    // this should never happen....
    static_assert(sizeof...(PARAMS_IN) + sizeof...(PARAMS_OUT) + 1 == sizeof...(PARAMS), "template error:expected 1+PARAMS_IN+PARAMS_OUT=PARAMS");

    // probably pointless templating...
    typename ITERATOR::value_type current_pattern;
    typename ITERATOR::value_type current_path;
    // I feel bad about a while(true) but this genuinely feels like the cleanest
    //  fastest way. Loop until we see a % or something goes wrong.
    while (true) {
        current_pattern = *pattern;
        current_path = *path;
        path++;
        pattern++;
        if (current_pattern == '%') {
            break;
        }
        else if (current_pattern != current_path) {
            return false;
        }
        else if (pattern == pattern_end || path == path_end) {
            return false;
        }

    }
    std::string raw_value(1,current_path);

    field_handler<VALUE> int_f;
    if (!int_f.try_append(current_path))
        return false;


    while (int_f.try_append(*path) && path != path_end) {
        path++;
    };


    return url_scan2(std::tuple<PARAMS_IN...>(), pattern, path, pattern_end, path_end, f, params..., int_f.get_value());
}

template<typename... PARAMS>
bool url_scan(std::string pattern, std::string path, std::function<void(PARAMS...)>& f) {
    // Have to do something awkward with tuples as parameter unpacking doesn't seem to work properly
    //  with explicit templates.
    return url_scan2(std::tuple<PARAMS...>(), pattern.begin(), path.begin(), pattern.end(), path.end(), f);
}

}
