cmake_minimum_required(VERSION 3.24)
project(SimplePendulum)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML COMPONENTS system window graphics REQUIRED)

add_executable(SimplePendulum src/Main.cpp src/Application.cpp src/Application.hpp src/SimplePendulum.cpp src/SimplePendulum.hpp)
target_link_libraries(SimplePendulum PRIVATE sfml-system sfml-window sfml-graphics)
