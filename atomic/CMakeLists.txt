cmake_minimum_required(VERSION 3.28)
project(CPPAtomic CXX)

set(CMAKE_CXX_STANDARD 23)

add_executable(demo1 atomic.cpp)
add_executable(leader compare_exchange_strong.cpp)
add_executable(wait wait_notify.cpp)