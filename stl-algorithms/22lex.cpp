#include <fmt/ranges.h>

#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

// 示例 1: lexicographical_compare, ranges::lexicographical_compare
void example_lexicographical_compare() {
  std::vector<int> first = {1, 2, 3};
  std::vector<int> second = {1, 2, 4};

  // 使用 std::lexicographical_compare
  bool stdResult = std::lexicographical_compare(first.begin(), first.end(),
                                                second.begin(), second.end());
  fmt::println("std::lexicographical_compare: {}", stdResult);
  // 预期输出: std::lexicographical_compare: true

  // 使用 std::ranges::lexicographical_compare
  bool rangesResult = std::ranges::lexicographical_compare(first, second);
  fmt::println("std::ranges::lexicographical_compare: {}", rangesResult);
  // 预期输出: std::ranges::lexicographical_compare: true
}

// 示例 2: lexicographical_compare_three_way
void example_lexicographical_compare_three_way() {
  std::vector<int> first = {1, 2, 3};
  std::vector<int> second = {1, 2, 4};

  // 使用 std::lexicographical_compare_three_way
  auto stdThreeWayResult = std::lexicographical_compare_three_way(
      first.begin(), first.end(), second.begin(), second.end());
  fmt::println("std::lexicographical_compare_three_way: {}",
               stdThreeWayResult < 0);
  // 预期输出: std::lexicographical_compare_three_way: true

  // 可以根据三路比较结果进行不同判断
  if (stdThreeWayResult < 0) {
    fmt::println("first is less than second");
  } else if (stdThreeWayResult > 0) {
    fmt::println("first is greater than second");
  } else {
    fmt::println("first is equal to second");
  }
}

int main() {
  example_lexicographical_compare();
  example_lexicographical_compare_three_way();
  return 0;
}
