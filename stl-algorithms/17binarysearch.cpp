#include <fmt/ranges.h>

#include <algorithm>
#include <array>
#include <ranges>

// 示例 1: lower_bound, ranges::lower_bound
void example_lower_bound() {
  constexpr std::array vec = {1, 2, 4, 4, 5, 6, 7};
  constexpr int target = 4;
  // 使用 std::lower_bound
  fmt::println("std::lower_bound: {}",
               std::lower_bound(vec.begin(), vec.end(), target) - vec.begin());
  // 预期输出: std::lower_bound: 2

  // 使用 std::ranges::lower_bound
  fmt::println("std::ranges::lower_bound: {}",
               std::ranges::lower_bound(vec, target) - vec.begin());
  // 预期输出: std::ranges::lower_bound: 2
}

// 示例 2: upper_bound, ranges::upper_bound
void example_upper_bound() {
  constexpr std::array vec = {1, 2, 4, 4, 5, 6, 7};
  constexpr int target = 4;
  // 使用 std::upper_bound
  fmt::println("std::upper_bound: {}",
               std::upper_bound(vec.begin(), vec.end(), target) - vec.begin());
  // 预期输出: std::upper_bound: 4

  // 使用 std::ranges::upper_bound
  fmt::println("std::ranges::upper_bound: {}",
               std::ranges::upper_bound(vec, target) - vec.begin());
  // 预期输出: std::ranges::upper_bound: 4
}

// 示例 3: equal_range, ranges::equal_range
void example_equal_range() {
  constexpr std::array vec = {1, 2, 4, 4, 5, 6, 7};
  constexpr int target = 4;
  // 使用 std::equal_range
  auto stdEqualRange = std::equal_range(vec.begin(), vec.end(), target);
  fmt::println("std::equal_range: [{}, {}]", stdEqualRange.first - vec.begin(),
               stdEqualRange.second - vec.begin());
  // 预期输出: std::equal_range: [2, 4]

  // 使用 std::ranges::equal_range
  auto rangesEqualRange = std::ranges::equal_range(vec, target);
  fmt::println("std::ranges::equal_range: [{}, {}]",
               rangesEqualRange.begin() - vec.begin(),
               rangesEqualRange.end() - vec.begin());
  // 预期输出: std::ranges::equal_range: [2, 4]
}

// 示例 4: binary_search, ranges::binary_search
void example_binary_search() {
  constexpr std::array vec = {1, 2, 4, 4, 5, 6, 7};
  constexpr int target1 = 4;
  constexpr int target2 = 3;
  // 使用 std::binary_search
  fmt::println("std::binary_search for {}: {}", target1,
               std::binary_search(vec.begin(), vec.end(), target1));
  // 预期输出: std::binary_search for 4: true
  fmt::println("std::binary_search for {}: {}", target2,
               std::binary_search(vec.begin(), vec.end(), target2));
  // 预期输出: std::binary_search for 3: false

  // 使用 std::ranges::binary_search
  fmt::println("std::ranges::binary_search for {}: {}", target1,
               std::ranges::binary_search(vec, target1));
  // 预期输出: std::ranges::binary_search for 4: true
  fmt::println("std::ranges::binary_search for {}: {}", target2,
               std::ranges::binary_search(vec, target2));
  // 预期输出: std::ranges::binary_search for 3: false
}

int main() {
  example_lower_bound();
  example_upper_bound();
  example_equal_range();
  example_binary_search();
  return 0;
}