//
// mime_types.cpp
// ~~~~~~~~~~~~~~
//
//
// Created by seedsone on 18-8-8.
//

#include "mime_types.hpp"

namespace http
{
    namespace server
    {
        namespace mime_types
        {
            
            struct mapping {
                const char *extension;
                const char *mime_type;
            } mappings[] =
                    {
                            {"gif",  "image/gif"},
                            {"htm",  "text/html"},
                            {"html", "text/html"},
                            {"jpg",  "image/jpeg"},
                            {"png",  "image/png"}
                    };
            
            std::string extension_to_type(const std::string &extension)
            {
                for (mapping m: mappings)
                {
                    if (m.extension == extension)
                    {
                        return m.mime_type;
                    }
                }
                
                return "text/plain";
            }
            
        } // namespace mime_types
    } // namespace fly-server
} // namespace http
