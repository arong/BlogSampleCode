cmake_minimum_required(VERSION 3.28)
project(CppModule CXX)

set(CMAKE_CXX_STANDARD 23)
# check if the compiler is gcc
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    if(CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 14)
        set(CMAKE_CXX_SCAN_FOR_MODULES ON)
    else()
        message(FATAL_ERROR "GCC version must be greater than 14")
    endif()
endif()

add_library(simple_module)
target_sources(simple_module
        PUBLIC
        FILE_SET CXX_MODULES FILES
        simple.ixx
)
add_executable(simple_demo simple_main.cpp)
target_link_libraries(simple_demo simple_module)


add_library(complex_module)
target_sources(complex_module
        PUBLIC
        FILE_SET CXX_MODULES FILES
        complex.ixx
)
add_executable(complex_demo complex_main.cpp)
target_link_libraries(complex_demo complex_module)


add_library(separate_module)
target_sources(separate_module
        PUBLIC
        FILE_SET CXX_MODULES FILES
        separate_interface.ixx
)
target_sources(separate_module PUBLIC separate_impl.ixx)

add_executable(separate_demo separate_main.cpp)
target_link_libraries(separate_demo separate_module)

add_library(sort_module)
target_sources(sort_module
        PUBLIC
        FILE_SET CXX_MODULES FILES
        sort.ixx
        sort_bubble.ixx
        sort_quick.ixx
        sort_insert.ixx
)
add_executable(sort_module_demo sort_main.cpp)
target_link_libraries(sort_module_demo sort_module)

add_library(partition_module)
target_sources(partition_module
        PUBLIC
        FILE_SET CXX_MODULES FILES
        partition.ixx
        partition_part1.ixx
        partition_part2.ixx
)
add_executable(partition_module_demo partition_main.cpp)
target_link_libraries(partition_module_demo partition_module)
