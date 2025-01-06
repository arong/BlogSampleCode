cmake_minimum_required(VERSION 3.28)

project(LatchAndBarrier CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(latch latch.cpp)
add_executable(latch2 latch_multi.cpp)
add_executable(barrier barrier.cpp)
add_executable(barrier_solution barrier_solution.cpp)
