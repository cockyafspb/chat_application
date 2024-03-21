cmake_minimum_required(VERSION 3.27)
project(server)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost REQUIRED)
find_package(nlohmann_json REQUIRED)

add_executable(server main.cpp
        Headers.h
        Listener.cpp
        Listener.h
        SocketConnection.cpp
        SocketConnection.h
        ChatRoom.cpp
        ChatRoom.h
        RoomsSingleton.cpp
        RoomsSingleton.h
        RoomCommand.h
        RoomMessage.h
        RoomsSingleton.cpp)
target_link_libraries(server nlohmann_json::nlohmann_json)

if (WIN32)
    set(libs ws2_32 wsock32)
    target_link_libraries(server ${libs})
endif()