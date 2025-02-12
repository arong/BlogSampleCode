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
