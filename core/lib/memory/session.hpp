//
// Created by seedsone on 18-8-27.
//

#ifndef SERVERFLY_SESSION_HPP
#define SERVERFLY_SESSION_HPP

#include <string>

namespace http::server
{
    class session
    {
    public:
        explicit session() = default;

    public:
        bool conf(std::string _conf_str);
        bool conf(std::string key, std::string value);

    public:
        bool set(std::string key, std::string value);
        bool set(const char* key, std::string value);
    };
}


#endif //SERVERFLY_SESSION_HPP
