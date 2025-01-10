cmake_minimum_required(VERSION 3.28)

project(jthreadDemo CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(thread_issue thread_issue.cpp)
add_executable(jthread jthread.cpp)
add_executable(stop_token stop_token.cpp)
add_executable(stop_callback stop_callback.cpp)
add_executable(stop_source stop_source.cpp)
