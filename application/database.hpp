//
// Created by seedsone on 18-8-8.
//

#ifndef SERVERFLY_DATABASE_HPP
#define SERVERFLY_DATABASE_HPP
typedef struct {
    char *host;
    unsigned short port;
    char *username;
    char *password;
    char *database;
} database;

database database_conf = {
        .host = "",
        .port = 3306,
        .username = "",
        .password = "",
        .database = ""
};
#endif //SERVERFLY_DATABASE_HPP
