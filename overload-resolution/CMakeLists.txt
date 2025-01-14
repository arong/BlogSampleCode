cmake_minimum_required(VERSION 3.28)

project(OverloadDemo CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(example1 example1.cpp)
add_executable(example3 example3.cpp)
add_executable(example4B example4B.cpp)
add_executable(exampleD exampleD.cpp)
add_executable(exampleF exampleF.cpp)
add_executable(exampleG exampleG.cpp)
add_executable(exampleH exampleH.cpp)
add_executable(qualification_adjustments qualification_adjustments.cpp.cpp)
add_executable(sample sample.cpp)

add_executable(example2A example2A.cpp)
add_executable(exampleC exampleC.cpp)
add_executable(exampleE exampleE.cpp)
add_executable(exampleJ exampleJ.cpp)
add_executable(example5 example5.cpp)
add_executable(invalid invalid.cpp)
add_executable(overload_error overload_error.cpp)
