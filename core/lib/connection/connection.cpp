//
// connection.cpp
// ~~~~~~~~~~~~~~
//
//
// Created by seedsone on 18-8-8.
//

#include "connection.hpp"
#include <utility>
#include <vector>
#include "connection_manager.hpp"
#include "../request/request_handler.hpp"
#include "../../server.hpp"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <string>

namespace http
{
    namespace server
    {
        std::vector<std::pair<const char*,const char*>> $_SERVER;   // 全局变量
        std::vector<std::pair<const char*,const char*>> $_REQUIRE;  // 全局变量

        connection::connection(boost::asio::ip::tcp::socket socket,
                               connection_manager &manager, request_handler &handler)
                : socket_(std::move(socket)),
                  connection_manager_(manager),
                  request_handler_(handler) {}

        void connection::start()
        {
            do_read();
        }

        void connection::stop()
        {
            socket_.close();
        }

        void connection::do_read()
        {
            auto self(shared_from_this());
            socket_.async_read_some(boost::asio::buffer(buffer_),
                                    [this, self](boost::system::error_code ec, std::size_t bytes_transferred) {
                                        if (!ec)
                                        {
                                            request_parser::result_type result;
                                            std::tie(result, std::ignore) = request_parser_.parse(
                                                    request_, buffer_.data(), buffer_.data() + bytes_transferred);  // 将返回的tuple解包
                                            set_global_var();
                                            if (result == request_parser::good)
                                            {
                                                request_handler_.handle_request(request_, reply_);
                                                do_write();
                                            }
                                            else if (result == request_parser::bad)
                                            {
                                                reply_ = reply::stock_reply(reply::bad_request);
                                                do_write();
                                            }
                                            else
                                            {
                                                do_read();
                                            }
                                        }
                                        else if (ec != boost::asio::error::operation_aborted)
                                        {
                                            connection_manager_.stop(shared_from_this());
                                        }
                                    });
        }

        void connection::set_global_var() const
        {
            std::vector<std::string> fields;
            split(fields, buffer_, boost::algorithm::is_any_of("\r\n"), boost::algorithm::token_compress_off);
            for (std::vector<std::string>::const_iterator iter = fields.cbegin(); iter != fields.cend(); iter++)
            {
                if(iter->length() == 0) continue;
                std::vector<std::string> line;
                split(line, *iter, boost::algorithm::is_any_of(":"), boost::algorithm::token_compress_off);
                if(line.size() == 2)
                {
                    $_REQUIRE.push_back(std::pair<const char *, const char *> (line[0].data(), line[1].data()));
                }
                else if(line.size() == 1)
                {
                    $_REQUIRE.push_back(std::pair<const char* , const char *>("Method",line[0].data()));
                }
            }
            return;
        }

        void connection::do_write()
        {
            auto self(shared_from_this());
            boost::asio::async_write(socket_, reply_.to_buffers(),
                                     [this, self](boost::system::error_code ec, std::size_t) {
                                         if (!ec)
                                         {
                                             // Initiate graceful connection closure.
                                             boost::system::error_code ignored_ec;
                                             socket_.shutdown(boost::asio::ip::tcp::socket::shutdown_both,
                                                              ignored_ec);
                                         }

                                         if (ec != boost::asio::error::operation_aborted)
                                         {
                                             connection_manager_.stop(shared_from_this());
                                         }
                                     });
        }

    } // namespace fly-server
} // namespace http
