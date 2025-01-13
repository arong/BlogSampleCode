# 设置最低的 CMake 版本
cmake_minimum_required(VERSION 3.28)

# 定义项目名称和其使用语言
project(CMakeDemo CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

enable_testing()
# FetchContent 模块
include(FetchContent)

# 添加 Google Test
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

# 设置编译选项，避免在构建测试时污染主工程的设置
set(GTEST_SHUFFLE 1)

# 创建测试可执行文件
add_executable(test.exe test.cpp)

# 链接 Google Test 库
target_link_libraries(test.exe PRIVATE gtest gtest_main)

# 添加测试到 CTest
add_test(NAME test.exe COMMAND test.exe)
