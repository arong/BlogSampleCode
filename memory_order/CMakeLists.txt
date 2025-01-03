cmake_minimum_required(VERSION 3.28)
project(memory_order CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(free free/free.cpp)
add_executable(relaxed relaxed/relaxed.cpp)
add_executable(release-acquire release-acquire/release.cpp)