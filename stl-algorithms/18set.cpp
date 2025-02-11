#include <fmt/ranges.h>

#include <algorithm>
#include <array>
#include <iostream>
#include <ranges>
#include <vector>

// 示例 1: includes, ranges::includes
void example_includes() {
  constexpr std::array larger = {1, 2, 3, 4, 5, 6};
  constexpr std::array smaller = {2, 4, 6};
  // 使用 std::includes
  fmt::println("std::includes: {}",
               std::includes(larger.begin(), larger.end(), smaller.begin(),
                             smaller.end()));
  // 预期输出: std::includes: true

  // 使用 std::ranges::includes
  fmt::println("std::ranges::includes: {}",
               std::ranges::includes(larger, smaller));
  // 预期输出: std::ranges::includes: true
}

// 示例 2: set_union, ranges::set_union
void example_set_union() {
  std::vector<int> first = {1, 3, 5, 7};
  std::vector<int> second = {2, 3, 6, 7};
  std::vector<int> result;
  // 使用 std::set_union
  std::set_union(first.begin(), first.end(), second.begin(), second.end(),
                 std::back_inserter(result));
  fmt::println("std::set_union: {}", result);
  // 预期输出: std::set_union: [1, 2, 3, 5, 6, 7]

  first = {1, 3, 5, 7};
  second = {2, 3, 6, 7};
  result.clear();
  // 使用 std::ranges::set_union
  std::ranges::set_union(first, second, std::back_inserter(result));
  fmt::println("std::ranges::set_union: {}", result);
  // 预期输出: std::ranges::set_union: [1, 2, 3, 5, 6, 7]
}

// 示例 3: set_intersection, ranges::set_intersection
void example_set_intersection() {
  std::vector<int> first = {1, 3, 5, 7};
  std::vector<int> second = {2, 3, 6, 7};
  std::vector<int> result;
  // 使用 std::set_intersection
  std::set_intersection(first.begin(), first.end(), second.begin(),
                        second.end(), std::back_inserter(result));
  fmt::println("std::set_intersection: {}", result);
  // 预期输出: std::set_intersection: [3, 7]

  first = {1, 3, 5, 7};
  second = {2, 3, 6, 7};
  result.clear();
  // 使用 std::ranges::set_intersection
  std::ranges::set_intersection(first, second, std::back_inserter(result));
  fmt::println("std::ranges::set_intersection: {}", result);
  // 预期输出: std::ranges::set_intersection: [3, 7]
}

// 示例 4: set_difference, ranges::set_difference
void example_set_difference() {
  std::vector<int> first = {1, 3, 5, 7};
  std::vector<int> second = {2, 3, 6, 7};
  std::vector<int> result;
  // 使用 std::set_difference
  std::set_difference(first.begin(), first.end(), second.begin(), second.end(),
                      std::back_inserter(result));
  fmt::println("std::set_difference: {}", result);
  // 预期输出: std::set_difference: [1, 5]

  first = {1, 3, 5, 7};
  second = {2, 3, 6, 7};
  result.clear();
  // 使用 std::ranges::set_difference
  std::ranges::set_difference(first, second, std::back_inserter(result));
  fmt::println("std::ranges::set_difference: {}", result);
  // 预期输出: std::ranges::set_difference: [1, 5]
}

// 示例 5: set_symmetric_difference, ranges::set_symmetric_difference
void example_set_symmetric_difference() {
  std::vector<int> first = {1, 3, 5, 7};
  std::vector<int> second = {2, 3, 6, 7};
  std::vector<int> result;
  // 使用 std::set_symmetric_difference
  std::set_symmetric_difference(first.begin(), first.end(), second.begin(),
                                second.end(), std::back_inserter(result));
  fmt::println("std::set_symmetric_difference: {}", result);
  // 预期输出: std::set_symmetric_difference: [1, 2, 5, 6]

  first = {1, 3, 5, 7};
  second = {2, 3, 6, 7};
  result.clear();
  // 使用 std::ranges::set_symmetric_difference
  std::ranges::set_symmetric_difference(first, second,
                                        std::back_inserter(result));
  fmt::println("std::ranges::set_symmetric_difference: {}", result);
  // 预期输出: std::ranges::set_symmetric_difference: [1, 2, 5, 6]
}

int main() {
  example_includes();
  example_set_union();
  example_set_intersection();
  example_set_difference();
  example_set_symmetric_difference();
  return 0;
}
