cmake_minimum_required(VERSION 3.28)

project(FilesystemDemo CXX)

set(CMAKE_CXX_STANDARD 23)

add_executable(nodiscard nodiscard.cpp)
add_executable(nodiscard20 nodiscard20.cpp)
add_executable(maybe_unused maybe_unused.cpp)
add_executable(fallthrough fallthrough.cpp)
add_executable(deprecated deprecated.cpp)
add_executable(no_unique_address no_unique_address.cpp)
add_executable(assume assume.cpp)
add_executable(carries_dependency carries_dependency.cpp)
