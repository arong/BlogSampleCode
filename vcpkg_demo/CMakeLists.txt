cmake_minimum_required(VERSION 3.19)
project(vcpkg_demo)

# 查找 fmt 库
find_package(fmt CONFIG REQUIRED)

# 添加可执行文件
add_executable(vcpkg_demo main.cpp)

# 链接 fmt 库
target_link_libraries(vcpkg_demo PRIVATE fmt::fmt)
