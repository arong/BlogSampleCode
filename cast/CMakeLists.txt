cmake_minimum_required(VERSION 3.28)

project(CastingDemo CXX)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-Wall)
add_executable(implicit-conversion 1-implicit-conversion.cpp)
add_executable(arithmetic-conversion 2-arithmetic-conversion.cpp)
add_executable(signed-conversion 3-signed-conversion.cpp)
add_executable(user-conversion 4-user-conversion.cpp)

add_executable(static-cast 5-static_cast.cpp)
add_executable(multi-hops 6-multi-hops.cpp)

add_executable(type-aliasing 14-type-aliasing.cpp)
add_executable(inheritance 7-inheritance.cpp)
add_executable(downcasting 8-downcasting.cpp)
add_executable(const_cast 9-const_cast.cpp)
add_executable(member-overload 10-member-overload.cpp)
add_executable(dynamic_cast 11-dynamic_cast.cpp)
add_executable(reinterpret_cast 12-reinterpret_cast.cpp)
add_executable(reinterpret-cast-private 13-reinterpret-cast-private.cpp)
