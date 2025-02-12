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

add_subdirectory(simple)
add_subdirectory(complex)
add_subdirectory(separate)
add_subdirectory(submodule)
add_subdirectory(partition)
