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
        core/driver/tpl/tpl.hpp application/config.hpp application/database.hpp application/index.cpp application/index.hpp application/route.hpp core/lib/loader/loader.cpp core/lib/loader/loader.hpp application/main/index.cpp application/main/index.hpp core/lib/controller/controller.cpp core/lib/controller/controller.hpp)

find_package(Boost 1.67.0)
find_package(Threads)

target_link_libraries(serverFly boost_system)
target_link_libraries(serverFly pthread)