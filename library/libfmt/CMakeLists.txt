cmake_minimum_required(VERSION 3.28)

project(fmt_demo CXX)

include(FetchContent)

FetchContent_Declare(
  fmt
  URL https://github.com/fmtlib/fmt/releases/download/11.1.3/fmt-11.1.3.zip
)
FetchContent_MakeAvailable(fmt)

add_executable(basic basic.cpp)
target_link_libraries(basic PRIVATE fmt::fmt)

add_executable(container container.cpp)
target_link_libraries(container PRIVATE fmt::fmt)

add_executable(stream stream.cpp)
target_link_libraries(stream PRIVATE fmt::fmt)
