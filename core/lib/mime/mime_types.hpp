//
// mime_types.hpp
// ~~~~~~~~~~~~~~
//
//
// Created by seedsone on 18-8-8.
//

#ifndef HTTP_MIME_TYPES_HPP
#define HTTP_MIME_TYPES_HPP

#include <string>

namespace http {
namespace server {
namespace mime_types {

/// Convert a file extension into a MIME type.
std::string extension_to_type(const std::string& extension);

} // namespace mime_types
} // namespace fly-server
} // namespace http

#endif // HTTP_MIME_TYPES_HPP
