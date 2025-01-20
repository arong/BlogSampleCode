cmake_minimum_required(VERSION 3.28)

project(OptimizeBuild CXX)

add_executable(demo demo.cpp)
target_precompile_headers(demo INTERFACE pch.h)
