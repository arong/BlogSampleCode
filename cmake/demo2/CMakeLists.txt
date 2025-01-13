# 设置最低的 CMake 版本
cmake_minimum_required(VERSION 3.10)

# 定义项目名称和其使用语言
project(CMakeDemo CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 查找 fmt 库
find_package(fmt CONFIG REQUIRED)

# 添加可执行文件
add_executable(demo.exe main.cpp)
# 链接 fmt 库
target_link_libraries(demo.exe PRIVATE fmt::fmt)
