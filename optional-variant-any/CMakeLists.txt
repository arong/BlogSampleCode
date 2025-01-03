cmake_minimum_required(VERSION 3.28)

project(AnyOptionalVariant CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(optional optional.cpp)
add_executable(variant variant.cpp)
add_executable(any any.cpp)
