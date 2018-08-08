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
  std::string method;
  std::string uri;
  int http_version_major;
  int http_version_minor;
  std::vector<header> headers;
};

} // namespace fly-server
} // namespace http

#endif // HTTP_REQUEST_HPP
