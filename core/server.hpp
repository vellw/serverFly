//
// fly-server.hpp
// ~~~~~~~~~~
//
//
// Created by seedsone on 18-8-8.
//

#ifndef HTTP_SERVER_HPP
#define HTTP_SERVER_HPP

#include <boost/asio.hpp>
#include <string>
#include "lib/connection/connection.hpp"
#include "lib/connection/connection_manager.hpp"
#include "lib/request/request_handler.hpp"
#include <vector>

namespace http
{
    namespace server
    {
        /// 定义全局变量
        extern std::vector<std::pair<const char *, const char *>> $_SERVER;
        extern std::vector<std::pair<const char *, const char *>> $_COOKIE;
        extern std::vector<std::pair<const char *, const char *>> $_REQUIRE;
        extern std::vector<std::pair<const char *, const char *>> $_REQUEST;
        extern std::vector<std::pair<const char *, const char *>> $_RESPONSE;
        
        ///  HTTP server 声明.
        
        class server {
        public:
            server(const server &) = delete;
            
            server &operator=(const server &) = delete;
            
            /// 显示构造
            explicit server(const std::string &address, const std::string &port,
                            const std::string &doc_root);
            
            /// Run the server's io_context loop.
            void run();
        
        private:
            /// Perform an asynchronous accept operation.
            void do_accept();
            
            /// Wait for a request to stop the server.
            void do_await_stop();
            
            /// The io_context used to perform asynchronous operations.
            boost::asio::io_context io_context_;
            
            /// The signal_set is used to register for process termination notifications.
            boost::asio::signal_set signals_;
            
            /// Acceptor used to listen for incoming connections.
            boost::asio::ip::tcp::acceptor acceptor_;
            
            /// The connection manager which owns all live connections.
            connection_manager connection_manager_;
            
            /// The handler for all incoming requests.
            request_handler request_handler_;
            
        };
        
    } // namespace fly-server
} // namespace http

#endif // HTTP_SERVER_HPP
