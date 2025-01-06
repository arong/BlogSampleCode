cmake_minimum_required(VERSION 3.28)

project(AsanSamples CXX)

add_compile_options(-fsanitize=address -g)
add_link_options(-fsanitize=address)

add_executable(global-buffer-overflow global-buffer-overflow.cpp)
add_executable(init-order init-order.cpp init-order-b.cpp)
add_executable(memory-leak memory-leak.cpp)
add_executable(out-of-bound out-of-bound.cpp)
add_executable(stack-buffer-overflow stack-buffer-overflow.cpp)
add_executable(use-after-free use-after-free.cpp)
add_executable(use-after-return use-after-return.cpp)
add_executable(use-after-scope use-after-scope.cpp)
