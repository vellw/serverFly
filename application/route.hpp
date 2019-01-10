//
// Created by seedsone on 18-8-8.
//

#ifndef SERVERFLY_ROUTE_HPP
#define SERVERFLY_ROUTE_HPP
typedef struct {
    char path[1024];
} route;

route route_conf = {
        .path = ""
};
#endif //SERVERFLY_ROUTE_HPP
