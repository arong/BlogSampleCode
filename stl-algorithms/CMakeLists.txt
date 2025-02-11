# 设置最低的 CMake 版本
cmake_minimum_required(VERSION 3.28)

# 定义项目名称和其使用语言
project(STLAlgorithmDemo CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# FetchContent 模块
include(FetchContent)

FetchContent_Declare(
  fmt
  URL https://github.com/fmtlib/fmt/releases/download/11.1.3/fmt-11.1.3.zip
)
FetchContent_MakeAvailable(fmt)

add_executable(01batch 01batch.cpp)
target_link_libraries(01batch PRIVATE fmt::fmt)

add_executable(02check 02check.cpp)
target_link_libraries(02check PRIVATE fmt::fmt)

add_executable(03find 03find.cpp)
target_link_libraries(03find PRIVATE fmt::fmt)

add_executable(04count 04count.cpp)
target_link_libraries(04count PRIVATE fmt::fmt)

add_executable(05compare 05compare.cpp)
target_link_libraries(05compare PRIVATE fmt::fmt)

add_executable(07copymove 07copymove.cpp)
target_link_libraries(07copymove PRIVATE fmt::fmt)

add_executable(08swap 08swap.cpp)
target_link_libraries(08swap PRIVATE fmt::fmt)

add_executable(09transform 09transform.cpp)
target_link_libraries(09transform PRIVATE fmt::fmt)

add_executable(10replace 10replace.cpp)
target_link_libraries(10replace PRIVATE fmt::fmt)

add_executable(11generate 11generate.cpp)
target_link_libraries(11generate PRIVATE fmt::fmt)

add_executable(12remove 12remove.cpp)
target_link_libraries(12remove PRIVATE fmt::fmt)

add_executable(13order 13order.cpp)
target_link_libraries(13order PRIVATE fmt::fmt)

add_executable(14sample 14sample.cpp)
target_link_libraries(14sample PRIVATE fmt::fmt)

add_executable(15partition 15partition.cpp)
target_link_libraries(15partition PRIVATE fmt::fmt)

add_executable(16sort 16sort.cpp)
target_link_libraries(16sort PRIVATE fmt::fmt)

add_executable(17binarysearch 17binarysearch.cpp)
target_link_libraries(17binarysearch PRIVATE fmt::fmt)

add_executable(18set 18set.cpp)
target_link_libraries(18set PRIVATE fmt::fmt)

add_executable(19merge 19merge.cpp)
target_link_libraries(19merge PRIVATE fmt::fmt)

add_executable(20heap 20heap.cpp)
target_link_libraries(20heap PRIVATE fmt::fmt)

add_executable(21minmax 21minmax.cpp)
target_link_libraries(21minmax PRIVATE fmt::fmt)

add_executable(22lex 22lex.cpp)
target_link_libraries(22lex PRIVATE fmt::fmt)

add_executable(23permutation 23permutation.cpp)
target_link_libraries(23permutation PRIVATE fmt::fmt)

add_executable(24numeric 24numeric.cpp)
target_link_libraries(24numeric PRIVATE fmt::fmt)
