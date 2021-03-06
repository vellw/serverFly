//
// main.cpp
// Created by seedsone on 18-8-8.
//
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include "core/server.hpp"

void help(int argc, char *argv[])
{
    // Check command line arguments.
    if (argc != 4)
    {
        std::cerr << "Usage: http_server <address> <port> <doc_root>\n";
        std::cerr << "  For IPv4, try:\n";
        std::cerr << "    receiver 0.0.0.0 80 .\n";
        std::cerr << "  For IPv6, try:\n";
        std::cerr << "    receiver 0::0 80 .\n";
        return;
    }
    return;
}

int main(int argc, char *argv[])
{
    try
    {
        // Initialise the serverFly.
        // http::server::server s(argv[1], argv[2], argv[3]);
        std::string ip_addr("127.0.0.1");
        std::string port_num("61001");
        std::string doc_root("../public/");
        
        // Run the serverFly until stopped.
        http::server::server * serv = http::server::server::get_instance(ip_addr, port_num, doc_root);
        serv->run();
        // 路由分发
        // ......
    }
    catch (std::exception &e)
    {
        std::cerr << "exception: " << e.what() << "\n";
    }
    
    return 0;
}
