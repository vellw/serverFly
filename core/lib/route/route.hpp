//
// Created by seedsone on 18-8-23.
//

#ifndef SERVERFLY_ROUTE_HPP
#define SERVERFLY_ROUTE_HPP

#include <string>
#include <vector>
/// 处理路由
namespace http {
    namespace server {
        class route
        {
        public:
            explicit route();
            explicit route(std::string rule);
            explicit route(std::vector<std::string> rule_list);
            route(const route&);
            virtual ~route();
        };
    }
}

#endif //SERVERFLY_ROUTE_HPP
