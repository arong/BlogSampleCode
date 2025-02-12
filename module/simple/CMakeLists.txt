add_library(simple_module)
target_sources(simple_module
        PUBLIC
        FILE_SET CXX_MODULES FILES
        simple.ixx
)
add_executable(simple_demo simple_main.cpp)
target_link_libraries(simple_demo simple_module)
