cmake_minimum_required(VERSION 3.28)
project(ExecutionDemo CXX)

set(CMAKE_CXX_STANDARD 17)

# add_compile_options(-O3)
add_executable(execution execution.cpp)
add_executable(reduce reduce.cpp)
