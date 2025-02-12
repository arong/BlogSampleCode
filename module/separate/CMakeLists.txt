add_library(separate_module)
target_sources(separate_module
        PUBLIC
        FILE_SET CXX_MODULES FILES
        separate_interface.ixx
)
target_sources(separate_module PUBLIC separate_impl.ixx)

add_executable(separate_demo separate_main.cpp)
target_link_libraries(separate_demo separate_module)
