cmake_minimum_required(VERSION 3.27)
project(server_tests)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost REQUIRED)
find_package(nlohmann_json REQUIRED)

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(server_tests
        main.cpp
        ../server/RoomsSingleton.cpp
        ../server/ChatRoom.cpp
        ../server/SocketConnection.cpp)

target_link_libraries(server_tests gtest_main)
target_link_libraries(server_tests nlohmann_json::nlohmann_json)

if (WIN32)
    set(libs ws2_32 wsock32)
    target_link_libraries(server_tests ${libs})
endif()

add_test(RoomsSingletonTest server_tests)