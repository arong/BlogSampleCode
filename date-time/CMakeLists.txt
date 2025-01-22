cmake_minimum_required(VERSION 3.28)

project(DatetimeDemo CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(ratio ratio.cpp)
add_executable(duration duration.cpp)
add_executable(clock clock.cpp)
add_executable(execution_time execution_time.cpp)
add_executable(timepoint timepoint.cpp)
add_executable(date date.cpp)
add_executable(sys_days sys_days.cpp)
add_executable(timezone timezone.cpp)
