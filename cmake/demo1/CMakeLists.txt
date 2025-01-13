# 设置最低的 CMake 版本
cmake_minimum_required(VERSION 3.10)

# 定义项目名称和版本
project(CMakeDemo VERSION 1.0)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 为不同的编译类型设置编译选项
# Debug 模式下开启调试信息和额外警告
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -Wextra -DDEBUG")

# Release 模式下开启优化
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

# 输出当前的编译类型（仅用于调试）
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# 添加可执行文件
add_executable(demo.exe main.cpp)
