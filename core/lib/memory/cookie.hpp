//
// Created by seedsone on 18-8-27.
//

#ifndef SERVERFLY_COOKIE_HPP
#define SERVERFLY_COOKIE_HPP

#include <string>

namespace http
{
    namespace server
    {
        class cookie
        {
        public:
            std::string key;
            std::string value;
        };
    }
}


#endif //SERVERFLY_COOKIE_HPP
