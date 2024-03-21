cmake_minimum_required(VERSION 3.27)
project(client_tests)

set(CMAKE_CXX_STANDARD 20)
find_package(Qt6 COMPONENTS Core Gui Test Widgets Network WebSockets REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

enable_testing(true)

add_executable(client_tests main.cpp
        TestQString.cpp
        TestQString.h
        TestSocketConnection.cpp
        TestSocketConnection.h
        ../client/SocketConnection.cpp)
target_link_libraries(client_tests Qt::Core Qt::Gui Qt::Test Qt::Widgets Qt::Network Qt::WebSockets)