# 设置最低的 CMake 版本
cmake_minimum_required(VERSION 3.28)

# 定义项目名称和其使用语言
project(CMakeDemo CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 引入 FetchContent 模块
include(FetchContent)

# 设置 Rapidjson 编译选项
set(RAPIDJSON_BUILD_TESTS OFF CACHE INTERNAL "")
set(RAPIDJSON_BUILD_DOC OFF CACHE INTERNAL "")
set(RAPIDJSON_BUILD_EXAMPLES OFF CACHE INTERNAL "")
set(RAPIDJSON_BUILD_CXX20 ON CACHE INTERNAL "")

FetchContent_Declare(
    rapidjson
    URL https://github.com/Tencent/rapidjson/archive/refs/tags/v1.1.0.zip
)
FetchContent_MakeAvailable(rapidjson)

add_executable(basic basic.cpp)
target_include_directories(basic PRIVATE ${rapidjson_SOURCE_DIR}/include)

add_executable(nested nested.cpp)
target_include_directories(nested PRIVATE ${rapidjson_SOURCE_DIR}/include)

add_executable(generate generate.cpp)
target_include_directories(generate PRIVATE ${rapidjson_SOURCE_DIR}/include)

add_executable(parse parse.cpp)
target_include_directories(parse PRIVATE ${rapidjson_SOURCE_DIR}/include)

add_executable(jsonpath jsonpath.cpp)
target_include_directories(jsonpath PRIVATE ${rapidjson_SOURCE_DIR}/include)
