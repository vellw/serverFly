cmake_minimum_required(VERSION 3.10)
project(serverFly)

set(CMAKE_CXX_STANDARD 11)

add_executable(serverFly main.cpp
        core/lib/connection/connection.cpp
        core/lib/connection/connection_manager.cpp
        core/lib/mime/mime_types.cpp
        core/lib/reply/reply.cpp
        core/lib/request/request_handler.cpp
        core/lib/request/request_parser.cpp
        core/server.cpp
        core/driver/driver.hpp
        core/driver/db/db.hpp
        core/driver/db/mysql/mysql.hpp
        core/driver/tpl/tpl.hpp
        application/config.hpp
        application/database.hpp
        application/index.cpp
        application/index.hpp
        application/route.hpp
        core/lib/loader/loader.cpp
        core/lib/loader/loader.hpp
        application/main/index.cpp
        application/main/index.hpp
        core/lib/controller/controller.cpp
        core/lib/controller/controller.hpp
        core/driver/tpl/tpl.cpp
        core/lib/exception/exception.cpp
        core/lib/exception/exception.hpp
        core/lib/route/route.cpp
        core/lib/route/route.hpp
        core/lib/url/url.cpp
        core/lib/url/url.hpp
        core/lib/session/session.cpp
        core/lib/session/session.hpp
        core/lib/cookie/cookie.cpp
        core/lib/cookie/cookie.hpp
        core/lib/http_define.hpp core/lib/response/response.cpp core/lib/response/response.hpp core/lib/response/response_handler.cpp core/lib/response/response_handler.hpp core/lib/response/response_parser.cpp core/lib/response/response_parser.hpp core/lib/configure/configure.cpp core/lib/configure/configure.hpp core/component/controller/base/base.cpp core/component/controller/base/base.hpp core/component/controller/controller/controller.cpp core/component/controller/controller/controller.hpp core/component/model/base/base.cpp core/component/model/base/base.hpp core/component/model/model/model.cpp core/component/model/model/model.hpp core/component/tpl/base/base.cpp core/component/tpl/base/base.hpp core/component/tpl/tpl/tpl.cpp core/component/tpl/tpl/tpl.hpp)

find_package(Boost 1.67.0)
find_package(Threads)

target_link_libraries(serverFly boost_system)
target_link_libraries(serverFly pthread)