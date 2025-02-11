#include <fmt/ranges.h>

#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

// 示例 1: fill, ranges::fill
void example_fill() {
  std::vector<int> v(6);
  // 使用 std::fill
  std::fill(v.begin(), v.end(), 9);
  fmt::println("std::fill: {}", v);
  // 预期输出: std::fill: [9, 9, 9, 9, 9, 9]

  v.resize(6);
  // 使用 std::ranges::fill
  std::ranges::fill(v, 9);
  fmt::println("std::ranges::fill: {}", v);
  // 预期输出: std::ranges::fill: [9, 9, 9, 9, 9, 9]
}

// 示例 2: fill_n, ranges::fill_n
void example_fill_n() {
  std::vector<int> v(6);
  // 使用 std::fill_n
  std::fill_n(v.begin(), 3, 5);
  fmt::println("std::fill_n: {}",
               v);  // 预期输出: std::fill_n: [5, 5, 5, 0, 0, 0]

  v.resize(6);
  // 使用 std::ranges::fill_n
  std::ranges::fill_n(v.begin(), 3, 5);
  fmt::println("std::ranges::fill_n: {}",
               v);  // 预期输出: std::ranges::fill_n: [5, 5, 5, 0, 0, 0]
}

// 示例 3: generate, ranges::generate
void example_generate() {
  std::vector<int> v(6);
  int counter = 1;
  auto generator = [&counter]() { return counter++; };
  // 使用 std::generate
  std::generate(v.begin(), v.end(), generator);
  fmt::println("std::generate: {}",
               v);  // 预期输出: std::generate: [1, 2, 3, 4, 5, 6]

  v.resize(6);
  counter = 1;
  // 使用 std::ranges::generate
  std::ranges::generate(v, generator);
  fmt::println("std::ranges::generate: {}",
               v);  // 预期输出: std::ranges::generate: [1, 2, 3, 4, 5, 6]
}

// 示例 4: generate_n, ranges::generate_n
void example_generate_n() {
  std::vector<int> v(6);
  int counter = 1;
  auto generator = [&counter]() { return counter++; };
  // 使用 std::generate_n
  std::generate_n(v.begin(), 3, generator);
  fmt::println("std::generate_n: {}",
               v);  // 预期输出: std::generate_n: [1, 2, 3, 0, 0, 0]

  v.resize(6);
  counter = 1;
  // 使用 std::ranges::generate_n
  std::ranges::generate_n(v.begin(), 3, generator);
  fmt::println("std::ranges::generate_n: {}",
               v);  // 预期输出: std::ranges::generate_n: [1, 2, 3, 0, 0, 0]
}

int main() {
  example_fill();
  example_fill_n();
  example_generate();
  example_generate_n();
  return 0;
}
