cmake_minimum_required(VERSION 3.28)

project(FilesystemDemo CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(usage usage.cpp)
add_executable(list list.cpp)
add_executable(stat stat.cpp)
add_executable(error error.cpp)
add_executable(pathop path.cpp)
