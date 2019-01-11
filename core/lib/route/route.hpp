//
// Created by seedsone on 18-8-23.
//

#ifndef SERVERFLY_ROUTE_HPP
#define SERVERFLY_ROUTE_HPP

#include <string>
#include <vector>
#include <map>
/// 处理路由
namespace http
{
    namespace server
    {
        class rule;
        
        class route
        {
        public:
            explicit route();
            
            explicit route(std::string rule);
            
            explicit route(rule _rule);
            
            explicit route(std::vector<std::string> rule_list);
            
            explicit route(std::vector<rule> rule_list);
            
            route(const route &);
            
            virtual ~route();
        };
        
        class rule
        {
        public:
            explicit rule();
            
            explicit rule(std::string url);
            
            explicit rule(std::string path, std::string action, std::string params);
            
            explicit rule(std::string path, std::string action, std::map<std::string, std::string> params);
            
            rule(const rule &);
            
            virtual ~rule();
        
        protected:
            std::string path;
            std::string action;
            std::string params_str;
            std::map<std::string, std::string> params;
        };
    }
}

#endif //SERVERFLY_ROUTE_HPP
