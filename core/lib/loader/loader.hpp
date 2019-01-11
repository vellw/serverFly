//
// Created by seedsone on 18-8-8.
//

#ifndef SERVERFLY_LOADER_HPP
#define SERVERFLY_LOADER_HPP

#include <string>

namespace http
{
    namespace server
    {
        class loader
        {
        public:
            loader() = default;
            
            loader(const loader &) = delete;
            
            virtual ~loader();
        
        public:
            int find(std::string classname);
        };
    }
}
#endif //SERVERFLY_LOADER_HPP
