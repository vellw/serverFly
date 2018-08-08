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
            // 解析模板
            class tpl
            {
            public:
                tpl() = default;
                tpl(const tpl&) = delete;
                virtual ~tpl();
            };
        }
    }
}
#endif //SERVERFLY_TPL_HPP
