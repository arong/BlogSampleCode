# CMake 3.28 has official support for C++ 20 named modules
cmake_minimum_required(VERSION 3.28)

project(AlgorithmStudy CXX)

set(CMAKE_CXX_STANDARD 23)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message(FATAL_ERROR "This project does not support GCC, use clang/msvc instead")
    # endif()
endif()

include(FetchContent)

# 添加 rapidjson
# 设置 Rapidjson 编译选项
# set(RAPIDJSON_BUILD_TESTS OFF CACHE INTERNAL "")
# set(RAPIDJSON_BUILD_DOC OFF CACHE INTERNAL "")
# set(RAPIDJSON_BUILD_EXAMPLES OFF CACHE INTERNAL "")
# set(RAPIDJSON_BUILD_CXX20 ON CACHE INTERNAL "")
# FetchContent_Declare(
#     rapidjson
#     URL https://github.com/Tencent/rapidjson/archive/refs/tags/v1.1.0.zip
# )
# FetchContent_MakeAvailable(rapidjson)

# 添加 fmt
FetchContent_Declare(
  fmt
  URL https://github.com/fmtlib/fmt/releases/download/11.1.3/fmt-11.1.3.zip
)
FetchContent_MakeAvailable(fmt)

# 添加 Google Test
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(Graph)
target_sources(
  Graph
  PUBLIC FILE_SET
         graph_module
  TYPE  CXX_MODULES
  BASE_DIRS ${PROJECT_SOURCE_DIR}
  FILES
         AdjMatrix.ixx
         AdjList.ixx
         GraphInterface.ixx
         BFS.ixx
         DFS.ixx
         TopologicalSort.ixx
)
target_link_libraries(Graph PRIVATE fmt::fmt)

add_subdirectory(Applications)
add_subdirectory(unittest)
