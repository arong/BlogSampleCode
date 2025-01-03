cmake_minimum_required(VERSION 3.28)
project(Coroutines CXX)
set(CMAKE_CXX_STANDARD 23)

add_executable(e1_hello_world coro.cpp)
add_executable(e2_coyield coyield.cpp)
add_executable(e3_coyield coyield2.cpp)
add_executable(e4_coreturn coreturn.cpp)

add_executable(generator generator.cpp)
add_executable(echo_server echo_server.cpp)
