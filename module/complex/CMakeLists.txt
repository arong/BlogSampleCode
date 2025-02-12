add_library(complex_module)
target_sources(complex_module
        PUBLIC
        FILE_SET CXX_MODULES FILES
        complex.ixx
)
add_executable(complex_demo complex_main.cpp)
target_link_libraries(complex_demo complex_module)
