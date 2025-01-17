cmake_minimum_required(VERSION 3.28)
project(ExceptionDemo CXX)

set(CMAKE_CXX_STANDARD 11)

add_executable(catch catch.cpp)
add_executable(exception exception.cpp)
add_executable(terminate terminate.cpp)
add_executable(unwinding unwinding.cpp)
