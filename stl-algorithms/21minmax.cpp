#include <fmt/ranges.h>

#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

// 示例 1: max, ranges::max
void example_max() {
  int a = 5, b = 10;
  // 使用 std::max
  fmt::println("std::max: {}", std::max(a, b));
  // 预期输出: std::max: 10

  // 使用 std::ranges::max
  fmt::println("std::ranges::max: {}", std::ranges::max(a, b));
  // 预期输出: std::ranges::max: 10
}

// 示例 2: max_element, ranges::max_element
void example_max_element() {
  std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
  // 使用 std::max_element
  fmt::println("std::max_element: {}",
               *std::max_element(numbers.begin(), numbers.end()));
  // 预期输出: std::max_element: 9

  // 使用 std::ranges::max_element
  fmt::println("std::ranges::max_element: {}",
               *std::ranges::max_element(numbers));
  // 预期输出: std::ranges::max_element: 9
}

// 示例 3: min, ranges::min
void example_min() {
  int a = 5, b = 10;
  // 使用 std::min
  fmt::println("std::min: {}", std::min(a, b));
  // 预期输出: std::min: 5

  // 使用 std::ranges::min
  fmt::println("std::ranges::min: {}", std::ranges::min(a, b));
  // 预期输出: std::ranges::min: 5
}

// 示例 4: min_element, ranges::min_element
void example_min_element() {
  std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
  // 使用 std::min_element
  fmt::println("std::min_element: {}",
               *std::min_element(numbers.begin(), numbers.end()));
  // 预期输出: std::min_element: 1

  // 使用 std::ranges::min_element
  fmt::println("std::ranges::min_element: {}",
               *std::ranges::min_element(numbers));
  // 预期输出: std::ranges::min_element: 1
}

// 示例 5: minmax, ranges::minmax
void example_minmax() {
  int a = 5, b = 10;
  // 使用 std::minmax
  auto stdMinMax = std::minmax(a, b);
  fmt::println("std::minmax: min = {}, max = {}", stdMinMax.first,
               stdMinMax.second);
  // 预期输出: std::minmax: min = 5, max = 10

  // 使用 std::ranges::minmax
  auto rangesMinMax = std::ranges::minmax(a, b);
  fmt::println("std::ranges::minmax: min = {}, max = {}", rangesMinMax.min,
               rangesMinMax.max);
  // 预期输出: std::ranges::minmax: min = 5, max = 10
}

// 示例 6: minmax_element, ranges::minmax_element
void example_minmax_element() {
  std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
  // 使用 std::minmax_element
  auto stdMinMaxElement = std::minmax_element(numbers.begin(), numbers.end());
  fmt::println("std::minmax_element: min = {}, max = {}",
               *stdMinMaxElement.first, *stdMinMaxElement.second);
  // 预期输出: std::minmax_element: min = 1, max = 9

  // 使用 std::ranges::minmax_element
  auto rangesMinMaxElement = std::ranges::minmax_element(numbers);
  fmt::println("std::ranges::minmax_element: min = {}, max = {}",
               *rangesMinMaxElement.min, *rangesMinMaxElement.max);
  // 预期输出: std::ranges::minmax_element: min = 1, max = 9
}

// 示例 7: clamp, ranges::clamp
void example_clamp() {
  int value = 15;
  int low = 10, high = 20;
  // 使用 std::clamp
  fmt::println("std::clamp: {}", std::clamp(value, low, high));
  // 预期输出: std::clamp: 15

  // 使用 std::ranges::clamp
  fmt::println("std::ranges::clamp: {}", std::ranges::clamp(value, low, high));
  // 预期输出: std::ranges::clamp: 15
}

int main() {
  example_max();
  example_max_element();
  example_min();
  example_min_element();
  example_minmax();
  example_minmax_element();
  example_clamp();
  return 0;
}
