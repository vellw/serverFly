//
// Created by seedsone on 18-8-27.
//

#ifndef SERVERFLY_SESSION_HPP
#define SERVERFLY_SESSION_HPP

#include <string>

namespace http::server
{
    // 处理session数据
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

        std::string get(std::string key);
        std::string get(const char* key);
    };

    // session服务类，用于http服务端处理session
    class session_service
    {
    public:
        explicit session_service() = delete;

    private:
    };
}


#endif //SERVERFLY_SESSION_HPP
