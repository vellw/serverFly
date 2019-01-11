//
// Created by seedsone on 18-8-8.
//

#ifndef SERVERFLY_TPL_HPP
#define SERVERFLY_TPL_HPP

#include <string>

namespace http
{
    namespace driver
    {
        namespace tpl
        {
            // 模板引擎
            class tpl
            {
            public:
                explicit tpl();
                
                tpl(const tpl &);
                
                virtual ~tpl();
            
            protected:
            
            };
        }
    }
}
#endif //SERVERFLY_TPL_HPP
