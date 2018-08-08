cmake_minimum_required(VERSION 3.10)
project(server)

set(CMAKE_CXX_STANDARD 11)

add_executable(server main.cpp connection.cpp connection_manager.cpp mime_types.cpp reply.cpp request_handler.cpp request_parser.cpp server.cpp)

find_package(Boost 1.67.0)
find_package(Threads)

target_link_libraries(server boost_system)
target_link_libraries(server pthread)