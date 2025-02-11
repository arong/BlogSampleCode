#include <fmt/ranges.h>

#include <algorithm>
#include <ranges>
#include <vector>

// 示例 1: swap
void example_swap() {
  int a = 5, b = 10;
  std::swap(a, b);
  fmt::println("std::swap: a = {}, b = {}", a, b);
  // 预期输出: std::swap: a = 10, b = 5
}

// 示例 2: swap_ranges, ranges::swap_ranges
void example_swap_ranges() {
  std::vector first = {1, 2, 3};
  std::vector second = {4, 5, 6};
  // 使用 std::swap_ranges
  std::swap_ranges(first.begin(), first.end(), second.begin());
  fmt::println("std::swap_ranges: first = {}, second = {}", first, second);
  // 预期输出: std::swap_ranges: first = [4, 5, 6], second = [1, 2, 3]

  first = {1, 2, 3};
  second = {4, 5, 6};
  // 使用 std::ranges::swap_ranges
  std::ranges::swap_ranges(first, second);
  fmt::println("std::ranges::swap_ranges: first = {}, second = {}", first,
               second);
  // 预期输出: std::ranges::swap_ranges: first = [4, 5, 6], second = [1, 2, 3]
}

// 示例 3: iter_swap
void example_iter_swap() {
  std::vector numbers = {1, 2, 3, 4, 5};
  auto iter1 = numbers.begin();
  auto iter2 = numbers.begin() + 2;
  // 使用 std::iter_swap
  std::iter_swap(iter1, iter2);
  fmt::println("std::iter_swap: {}", numbers);
  // 预期输出: std::iter_swap: [3, 2, 1, 4, 5]
}

int main() {
  example_swap();
  example_swap_ranges();
  example_iter_swap();
  return 0;
}