#include <fmt/ranges.h>

#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

// 示例 1: sort, ranges::sort
void example_sort() {
  std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
  // 使用 std::sort
  std::sort(numbers.begin(), numbers.end());
  fmt::println("std::sort: {}", numbers);
  // 预期输出: std::sort: [1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 9]

  numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
  // 使用 std::ranges::sort
  std::ranges::sort(numbers);
  fmt::println("std::ranges::sort: {}", numbers);
  // 预期输出: std::ranges::sort: [1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 9]
}

// 示例 2: stable_sort, ranges::stable_sort
void example_stable_sort() {
  std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
  // 使用 std::stable_sort
  std::stable_sort(numbers.begin(), numbers.end());
  fmt::println("std::stable_sort: {}", numbers);
  // 预期输出: 元素升序排列且相等元素相对顺序不变的向量，例如 [1, 1, 2, 3, 3, 4,
  // 5, 5, 5, 6, 9]

  numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
  // 使用 std::ranges::stable_sort
  std::ranges::stable_sort(numbers);
  fmt::println("std::ranges::stable_sort: {}", numbers);
  // 预期输出: 元素升序排列且相等元素相对顺序不变的向量，例如 [1, 1, 2, 3, 3, 4,
  // 5, 5, 5, 6, 9]
}

// 示例 3: partial_sort, ranges::partial_sort
void example_partial_sort() {
  std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
  // 使用 std::partial_sort 对前 5 个元素排序
  std::partial_sort(numbers.begin(), numbers.begin() + 5, numbers.end());
  fmt::println("std::partial_sort: {}", numbers);
  // 预期输出: 前 5 个元素升序排列，后面元素无序，例如 [1, 1, 2, 3, 3, 9, 5, 6,
  // 5, 4, 5]

  numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
  // 使用 std::ranges::partial_sort 对前 5 个元素排序
  std::ranges::partial_sort(numbers.begin(), numbers.begin() + 5,
                            numbers.end());
  fmt::println("std::ranges::partial_sort: {}", numbers);
  // 预期输出: 前 5 个元素升序排列，后面元素无序，例如 [1, 1, 2, 3, 3, 9, 5, 6,
  // 5, 4, 5]
}

// 示例 4: partial_sort_copy, ranges::partial_sort_copy
void example_partial_sort_copy() {
  std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
  std::vector<int> result(5);
  // 使用 std::partial_sort_copy
  std::partial_sort_copy(numbers.begin(), numbers.end(), result.begin(),
                         result.end());
  fmt::println("std::partial_sort_copy: {}", result);
  // 预期输出: 原向量中最小的 5 个元素升序排列的向量，例如 [1, 1, 2, 3, 3]

  numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
  result.clear();
  result.resize(5);
  // 使用 std::ranges::partial_sort_copy
  std::ranges::partial_sort_copy(numbers, result);
  fmt::println("std::ranges::partial_sort_copy: {}", result);
  // 预期输出: 原向量中最小的 5 个元素升序排列的向量，例如 [1, 1, 2, 3, 3]
}

// 示例 5: is_sorted, ranges::is_sorted
void example_is_sorted() {
  std::vector<int> numbers = {1, 2, 3, 4, 5};
  // 使用 std::is_sorted
  bool stdIsSorted = std::is_sorted(numbers.begin(), numbers.end());
  fmt::println("std::is_sorted: {}", stdIsSorted);
  // 预期输出: std::is_sorted: true

  numbers = {3, 1, 4};
  // 使用 std::ranges::is_sorted
  bool rangesIsSorted = std::ranges::is_sorted(numbers);
  fmt::println("std::ranges::is_sorted: {}", rangesIsSorted);
  // 预期输出: std::ranges::is_sorted: false
}

// 示例 6: is_sorted_until, ranges::is_sorted_until
void example_is_sorted_until() {
  std::vector<int> numbers = {1, 2, 3, 1, 4};
  // 使用 std::is_sorted_until
  auto stdSortedUntil = std::is_sorted_until(numbers.begin(), numbers.end());
  fmt::println("std::is_sorted_until: {}", *stdSortedUntil);
  // 预期输出: std::is_sorted_until: 1

  numbers = {1, 2, 3, 1, 4};
  // 使用 std::ranges::is_sorted_until
  auto rangesSortedUntil = std::ranges::is_sorted_until(numbers);
  fmt::println("std::ranges::is_sorted_until: {}", *rangesSortedUntil);
  // 预期输出: std::ranges::is_sorted_until: 1
}

// 示例 7: nth_element, ranges::nth_element
void example_nth_element() {
  std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
  // 使用 std::nth_element 找到第 5 小的元素（索引为 4）
  std::nth_element(numbers.begin(), numbers.begin() + 4, numbers.end());
  fmt::println("std::nth_element: {}", numbers[4]);
  // 预期输出: 第 5 小的元素，例如 3

  numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
  // 使用 std::ranges::nth_element 找到第 5 小的元素（索引为 4）
  std::ranges::nth_element(numbers, numbers.begin() + 4);
  fmt::println("std::ranges::nth_element: {}", numbers[4]);
  // 预期输出: 第 5 小的元素，例如 3
}

int main() {
  example_sort();
  example_stable_sort();
  example_partial_sort();
  example_partial_sort_copy();
  example_is_sorted();
  example_is_sorted_until();
  example_nth_element();
  return 0;
}
