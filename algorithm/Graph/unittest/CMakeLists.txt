add_executable(testAdjMatrix testAdjMatrix.cpp)
target_link_libraries(testAdjMatrix PRIVATE Graph GTest::gtest GTest::gtest_main)

add_test(NAME testAdjMatrix COMMAND testAdjMatrix)

add_executable(testAdjList testAdjList.cpp)
target_link_libraries(testAdjList PRIVATE Graph GTest::gtest GTest::gtest_main)

add_test(NAME testAdjList COMMAND testAdjList)
