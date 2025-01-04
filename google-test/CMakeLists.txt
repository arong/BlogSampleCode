cmake_minimum_required(VERSION 3.28)
project(GoogleTestDemo CXX)
# set(CMAKE_CXX_STANDARD 20)

enable_testing()

find_package(GTest CONFIG REQUIRED)

add_executable(basic basic.cpp)
target_link_libraries(basic PRIVATE GTest::gtest GTest::gtest_main GTest::gmock
                                    GTest::gmock_main)

add_test(BasicTest basic)

add_executable(exception exception.cpp)
target_link_libraries(exception PRIVATE GTest::gtest GTest::gtest_main
                                        GTest::gmock GTest::gmock_main)

add_test(ExceptionTest exception)

add_executable(exit exit.cpp)
target_link_libraries(exit PRIVATE GTest::gtest GTest::gtest_main
                                        GTest::gmock GTest::gmock_main)

add_test(ExitTest exit)


add_executable(app_test app_test.cpp)
target_link_libraries(app_test PRIVATE GTest::gtest GTest::gtest_main
                                        GTest::gmock GTest::gmock_main)

add_test(AppTest app_test)
