//
// Created by seedsone on 18-8-23.
//

#include "route.hpp"
namespace http::server
{
    route::route() {}

    route::route(http::server::rule _rule) {}

    route::route(std::string rule) {}

    route::route(std::vector<http::server::rule> rule_list) {}

    route::route(std::vector<std::string> rule_list) {}

    route::route(const http::server::route &) {}

    route::~route() {}
}

namespace http::server
{
    rule::rule() {}

    rule::rule(const http::server::rule &) {}

    rule::rule(std::string url) {}

    rule::rule(std::string path, std::string action, std::string params)
        : path(path) , action(action) , params_str(params)
    {}

    rule::rule(std::string path, std::string action, std::map<std::string, std::string> params)
        : path(path) , action(action) , params(params)
    {}
    rule::~rule() {}
}
