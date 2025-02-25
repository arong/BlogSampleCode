add_executable(AdjMatrixDemo AdjMatrixDemo.cpp)
target_link_libraries(AdjMatrixDemo PRIVATE Graph fmt::fmt)

add_executable(AdjListDemo AdjListDemo.cpp)
target_link_libraries(AdjListDemo PRIVATE Graph fmt::fmt)

add_executable(BFSDemo BFSDemo.cpp)
target_link_libraries(BFSDemo PRIVATE Graph fmt::fmt)

add_executable(DFSDemo DFSDemo.cpp)
target_link_libraries(DFSDemo PRIVATE Graph fmt::fmt)

add_executable(TopoDemo TopoDemo.cpp)
target_link_libraries(TopoDemo PRIVATE Graph fmt::fmt)

add_executable(BellmanFordDemo BellmanFordDemo.cpp)
target_link_libraries(BellmanFordDemo PRIVATE Graph fmt::fmt)

add_executable(SCCDemo SCCDemo.cpp)
target_link_libraries(SCCDemo PRIVATE Graph fmt::fmt)

add_executable(HungarianDemo HungarianDemo.cpp)
target_link_libraries(HungarianDemo PRIVATE Graph fmt::fmt)

add_executable(EulerDemo EulerDemo.cpp)
target_link_libraries(EulerDemo PRIVATE Graph fmt::fmt)

add_executable(APSPDemo APSPDemo.cpp)
target_link_libraries(APSPDemo PRIVATE Graph fmt::fmt)
