//
// Created by seedsone on 18-8-8.
//

#ifndef SERVERFLY_INDEX_HPP
#define SERVERFLY_INDEX_HPP
namespace app
{
    class base
    {
    public:
        base() = default;
        
        base(const base &) = delete;
        
        virtual ~base();
    };
}
#endif //SERVERFLY_INDEX_HPP
