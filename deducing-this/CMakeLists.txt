cmake_minimum_required(VERSION 3.28)

project(FilesystemDemo CXX)

set(CMAKE_CXX_STANDARD 23)
add_executable(left_right_ref lr.cpp)
add_executable(left_right_ref_dt lr_dt.cpp)

add_executable(perfect_forwarding pf.cpp)
add_executable(perfect_forwarding_dt pf_dt.cpp)

add_executable(chained_call tc.cpp)
add_executable(chained_call_dt tc_dt.cpp)

add_executable(const const.cpp)
add_executable(const_dt const_dt.cpp)

add_executable(crtp crtp.cpp)
add_executable(crtp_dt crtp_dt.cpp)
