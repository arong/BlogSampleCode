add_executable(AdjMatrixDemo AdjMatrixDemo.cpp)
target_link_libraries(AdjMatrixDemo PRIVATE Graph fmt::fmt)

add_executable(AdjListDemo AdjListDemo.cpp)
target_link_libraries(AdjListDemo PRIVATE Graph fmt::fmt)

add_executable(BFSDemo BFSDemo.cpp)
target_link_libraries(BFSDemo PRIVATE Graph fmt::fmt)

add_executable(DFSDemo DFSDemo.cpp)
target_link_libraries(DFSDemo PRIVATE Graph fmt::fmt)
