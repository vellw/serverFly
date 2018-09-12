//
// header.hpp
// ~~~~~~~~~~
//
//
// Created by seedsone on 18-8-8.
//

#ifndef HTTP_HEADER_HPP
#define HTTP_HEADER_HPP

#include <string>

namespace http {
namespace server {

struct header
{
  std::string key;
  std::string value;
};

} // namespace fly-server
} // namespace http

#endif // HTTP_HEADER_HPP
