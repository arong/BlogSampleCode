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
