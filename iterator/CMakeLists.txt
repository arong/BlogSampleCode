cmake_minimum_required(VERSION 3.28)

project(IteratorDemo CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(iterator iterator.cpp)
add_executable(random_iterator random_iterator.cpp)
add_executable(bidirectional_iterators bidirectional_iterators.cpp)
add_executable(forward_iterators forward_iterators.cpp)
