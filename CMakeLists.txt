cmake_minimum_required(VERSION 3.27)
project(client_server)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(server)
add_subdirectory(client)
add_subdirectory(server_tests)
add_subdirectory(client_tests)