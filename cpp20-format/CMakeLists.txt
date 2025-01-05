cmake_minimum_required(VERSION 3.28)
project(ExpectedDemo CXX)

set(CMAKE_CXX_STANDARD 23)

add_executable(print print.cpp)
add_executable(println println.cpp)
add_executable(format format.cpp)

add_executable(custom custom.cpp)

option(ENABLE_LIBFMT "enable libfmt demo" OFF)
if (ENABLE_LIBFMT)
    find_package(fmt CONFIG REQUIRED)
    add_executable(fmt_demo fmt_demo.cpp)
    target_link_libraries(fmt_demo PRIVATE fmt::fmt)
endif()
