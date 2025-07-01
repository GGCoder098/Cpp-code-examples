cmake_minimum_required(VERSION 3.31)
project(Client)

set(CMAKE_CXX_STANDARD 14)

add_executable(Client
        winsocket_Client.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} Ws2_32)