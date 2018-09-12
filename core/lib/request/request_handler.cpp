//
// request_handler.cpp
// ~~~~~~~~~~~~~~~~~~~
//
//
// Created by seedsone on 18-8-8.
//
//

#include "request_handler.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include "../mime/mime_types.hpp"
#include "../reply/reply.hpp"
#include "request.hpp"
#include "../http_define.hpp"

namespace http {
    namespace server {

        request_handler::request_handler(const std::string &doc_root)
                : doc_root_(doc_root)
        {

        }

        void request_handler::handle_request(const request &req, reply &rep)
        {
            // Decode url to path.
            std::string request_path;
            if (!url_decode(req.uri, request_path))
            {
                rep = reply::stock_reply(reply::bad_request);
                return;
            }

            // Request path must be absolute and not contain "..".
            if ( request_path.empty() )
            {
                rep = reply::stock_reply(reply::bad_request);
                return;
            }

            if( request_path[0] != '/')
            {
                rep = reply::stock_reply(reply::bad_request);
                return;
            }

            if( request_path.find("..") != std::string::npos )
            {
                rep = reply::stock_reply(reply::bad_request);
                return;
            }


            // If path ends in slash (i.e. is a directory) then add "main.html".
            if (request_path[request_path.size() - 1] == '/')
            {
                request_path += "index.html"; // 默认入口
            }

            // Determine the file extension.
            std::size_t last_slash_pos = request_path.find_last_of("/");
            std::size_t last_dot_pos = request_path.find_last_of(".");
            std::string extension;
            if (last_dot_pos != std::string::npos && last_dot_pos > last_slash_pos)
            {
                extension = request_path.substr(last_dot_pos + 1);
            }

            // 打开要输出到客户端（浏览器）的文件
            std::string full_path = doc_root_ + request_path;
            std::ifstream in_file_stream(full_path.c_str(), std::ios::in | std::ios::binary);
            if (!in_file_stream)
            {
                rep = reply::stock_reply(reply::not_found);
                return;
            }

            // 构造发送给客户端（浏览器）的内容
            rep.status = reply::ok;
            const size_t max_buf_size = 1024;
            char buf[max_buf_size];

            while (in_file_stream.read(buf, sizeof(buf)).gcount() > 0)
            {
                rep.content.append(buf, in_file_stream.gcount());
            }

            const size_t max_header_counts = 12;
            rep.headers.resize(max_header_counts);

            rep.headers[HTTP_HEADER_ALLOW].key = "Allow";
            rep.headers[HTTP_HEADER_ALLOW].value = "*";

            rep.headers[HTTP_HEADER_CONTENT_ENCODING].key = "Content-Encoding";
            rep.headers[HTTP_HEADER_CONTENT_ENCODING].value = "*";

            rep.headers[HTTP_HEADER_CONTENT_LENGTH].key = "Content-Length";
            rep.headers[HTTP_HEADER_CONTENT_LENGTH].value = std::to_string(rep.content.size());

            rep.headers[HTTP_HEADER_CONTENT_TYPE].key = "Content-Type";
            rep.headers[HTTP_HEADER_CONTENT_TYPE].value = mime_types::extension_to_type(extension);

            rep.headers[HTTP_HEADER_DATE].key = "Date";
            rep.headers[HTTP_HEADER_DATE].value = "*";

            rep.headers[HTTP_HEADER_EXPIRES].key = "Expires";
            rep.headers[HTTP_HEADER_EXPIRES].value = "*";

            rep.headers[HTTP_HEADER_LAST_MODIFIED].key = "Last-Modified";
            rep.headers[HTTP_HEADER_LAST_MODIFIED].value = "*";

            rep.headers[HTTP_HEADER_LOCATION].key = "Location";
            rep.headers[HTTP_HEADER_LOCATION].value = "*";

            rep.headers[HTTP_HEADER_REFRESH].key = "Refresh";
            rep.headers[HTTP_HEADER_REFRESH].value = "*";

            rep.headers[HTTP_HEADER_SERVER].key = "Server";
            rep.headers[HTTP_HEADER_SERVER].value = "*";

            rep.headers[HTTP_HEADER_SET_COOKIE].key = "Set-Cookie";
            rep.headers[HTTP_HEADER_SET_COOKIE].value = "*";

            rep.headers[HTTP_HEADER_WWW_AUTHENTICATE].key = "WWW-Authenticate";
            rep.headers[HTTP_HEADER_WWW_AUTHENTICATE].value = "*";

        }

        bool request_handler::url_decode(const std::string &in, std::string &out)
        {
            out.clear();
            out.reserve(in.size());
            for (std::size_t i = 0; i < in.size(); ++i)
            {
                if (in[i] == '%')
                {
                    if (i + 3 <= in.size())
                    {
                        int value = 0;
                        std::istringstream is(in.substr(i + 1, 2));
                        if (is >> std::hex >> value)
                        {
                            out += static_cast<char>(value);
                            i += 2;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (in[i] == '+')
                {
                    out += ' ';
                }
                else
                {
                    out += in[i];
                }
            }
            return true;
        }

    } // namespace fly-server
} // namespace http
