cmake_minimum_required(VERSION 3.31)
project(Server)

set(CMAKE_CXX_STANDARD 14)

add_executable(Server
        winsocket_server.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME} ws2_32)
