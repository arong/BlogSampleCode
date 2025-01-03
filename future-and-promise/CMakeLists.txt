cmake_minimum_required(VERSION 3.28)
project(Task CXX)
set(CMAKE_CXX_STANDARD 20)

add_executable(task task.cpp)
add_executable(async async.cpp)
add_executable(promise promise.cpp)
add_executable(promise_exception promise_exception.cpp)
add_executable(promise_lifecycle promise_lifecycle.cpp)