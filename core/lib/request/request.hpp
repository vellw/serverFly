//
// request.hpp
// ~~~~~~~~~~~
//
//
// Created by seedsone on 18-8-8.
//

#ifndef HTTP_REQUEST_HPP
#define HTTP_REQUEST_HPP

#include <string>
#include <vector>
#include "../../header.hpp"

namespace http {
namespace server {

/// A request received from a client.
struct request
{
  std::string method;           // 请求方法
  std::string uri;              // uri
  int http_version_major;       // http 主版本
  int http_version_minor;       // http 次版本
  std::vector<header> headers;  // http 头部
  std::string body;             // http body
};

} // namespace fly-server
} // namespace http

#endif // HTTP_REQUEST_HPP
