cmake_minimum_required(VERSION 3.28)

project(FilesystemDemo CXX)

set(CMAKE_CXX_STANDARD 23)

add_executable(storage storage.cpp)
add_executable(variable variable.cpp)
add_executable(function function.cpp)
add_executable(pointer pointer.cpp)
add_executable(pointer_constexpr pointer_constexpr.cpp)
add_executable(reference reference.cpp)
