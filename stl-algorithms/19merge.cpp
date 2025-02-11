#include <fmt/ranges.h>

#include <algorithm>
#include <ranges>
#include <vector>

// 示例 1: merge, ranges::merge
void example_merge() {
  constexpr std::array first = {1, 3, 5};
  constexpr std::array second = {2, 4, 6};
  std::vector<int> result;

  // 使用 std::merge
  std::merge(first.begin(), first.end(), second.begin(), second.end(),
             std::back_inserter(result));
  fmt::println("std::merge: {}", result);
  // 预期输出: std::merge: [1, 2, 3, 4, 5, 6]

  result.clear();
  // 使用 std::ranges::merge
  std::ranges::merge(first, second, std::back_inserter(result));
  fmt::println("std::ranges::merge: {}", result);
  // 预期输出: std::ranges::merge: [1, 2, 3, 4, 5, 6]
}

// 示例 2: inplace_merge, ranges::inplace_merge
void example_inplace_merge() {
  std::vector v = {1, 3, 5, 2, 4, 6};
  auto middle = v.begin() + 3;

  // 使用 std::inplace_merge
  std::inplace_merge(v.begin(), middle, v.end());
  fmt::println("std::inplace_merge: {}", v);
  // 预期输出: std::inplace_merge: [1, 2, 3, 4, 5, 6]

  v = {1, 3, 5, 2, 4, 6};
  middle = v.begin() + 3;
  // 使用 std::ranges::inplace_merge
  std::ranges::inplace_merge(v, middle);
  fmt::println("std::ranges::inplace_merge: {}", v);
  // 预期输出: std::ranges::inplace_merge: [1, 2, 3, 4, 5, 6]
}

int main() {
  example_merge();
  example_inplace_merge();
  return 0;
}
