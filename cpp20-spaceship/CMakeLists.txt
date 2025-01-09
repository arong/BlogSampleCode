cmake_minimum_required(VERSION 3.28)

project(FilesystemDemo CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(spaceship spaceship.cpp)
add_executable(strong_order strong_order.cpp)
add_executable(weak_order weak_order.cpp)
add_executable(partial_order partial_order.cpp)
add_executable(strong_equality strong_equality.cpp)
add_executable(weak_equality weak_equality.cpp)
