cmake_minimum_required(VERSION 3.28)
project(ExpectedDemo CXX)

set(CMAKE_CXX_STANDARD 23)

# 基本样例
add_executable(basic expect.cpp)

# transform 样例
add_executable(transform transform.cpp)

# and_then 样例
add_executable(and_then and_then.cpp)

# transform_error 样例
add_executable(transform_error transform_error.cpp)

# or_else 样例
add_executable(or_else or_else.cpp)
