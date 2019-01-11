//
// Created by seedsone on 18-8-8.
//

#ifndef SERVERFLY_CONTROLLER_HPP
#define SERVERFLY_CONTROLLER_HPP

namespace http
{
    namespace server
    {
        class controller
        {
        public:
            controller() = default;
            
            controller(const controller &) = delete;
            
            virtual ~controller();
        };
    }
}


#endif //SERVERFLY_CONTROLLER_HPP
