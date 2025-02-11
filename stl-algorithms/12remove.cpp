#include <fmt/ranges.h>

#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

// 示例 1: remove, ranges::remove
void example_remove() {
  std::vector<int> src = {1, 2, 3, 2, 4, 2};
  // 使用 std::remove
  auto newEnd = std::remove(src.begin(), src.end(), 2);
  fmt::println("std::remove: {}", std::vector<int>(src.begin(), newEnd));
  // 预期输出: std::remove: [1, 3, 4]

  src = {1, 2, 3, 2, 4, 2};
  // 使用 std::ranges::remove
  auto result = std::ranges::remove(src, 2);
  src.erase(result.begin(), result.end());
  fmt::println("std::ranges::remove: {}", src);
  // 预期输出: std::ranges::remove: [1, 3, 4]
}

// 示例 2: remove_if, ranges::remove_if
void example_remove_if() {
  std::vector<int> src = {1, 2, 3, 4, 5, 6};
  // 使用 std::remove_if
  auto newEnd = std::remove_if(src.begin(), src.end(),
                               [](int num) { return num % 2 == 0; });
  fmt::println("std::remove_if: {}", std::vector<int>(src.begin(), newEnd));
  // 预期输出: std::remove_if: [1, 3, 5]

  src = {1, 2, 3, 4, 5, 6};
  // 使用 std::ranges::remove_if
  auto result =
      std::ranges::remove_if(src, [](int num) { return num % 2 == 0; });
  src.erase(result.begin(), result.end());
  fmt::println("std::ranges::remove_if: {}", src);
  // 预期输出: std::ranges::remove_if: [1, 3, 5]
}

// 示例 3: remove_copy, ranges::remove_copy
void example_remove_copy() {
  std::vector<int> src = {1, 2, 3, 2, 4, 2};
  std::vector<int> result;
  // 使用 std::remove_copy
  std::remove_copy(src.begin(), src.end(), std::back_inserter(result), 2);
  fmt::println("std::remove_copy: {}", result);
  // 预期输出: std::remove_copy: [1, 3, 4]

  src = {1, 2, 3, 2, 4, 2};
  result.clear();
  // 使用 std::ranges::remove_copy
  std::ranges::remove_copy(src, std::back_inserter(result), 2);
  fmt::println("std::ranges::remove_copy: {}", result);
  // 预期输出: std::ranges::remove_copy: [1, 3, 4]
}

// 示例 4: remove_copy_if, ranges::remove_copy_if
void example_remove_copy_if() {
  std::vector<int> src = {1, 2, 3, 4, 5, 6};
  std::vector<int> result;
  // 使用 std::remove_copy_if
  std::remove_copy_if(src.begin(), src.end(), std::back_inserter(result),
                      [](int num) { return num % 2 == 0; });
  fmt::println("std::remove_copy_if: {}", result);
  // 预期输出: std::remove_copy_if: [1, 3, 5]

  src = {1, 2, 3, 4, 5, 6};
  result.clear();
  // 使用 std::ranges::remove_copy_if
  std::ranges::remove_copy_if(src, std::back_inserter(result),
                              [](int num) { return num % 2 == 0; });
  fmt::println("std::ranges::remove_copy_if: {}", result);
  // 预期输出: std::ranges::remove_copy_if: [1, 3, 5]
}

// 示例 5: unique, ranges::unique
void example_unique() {
  std::vector<int> src = {1, 1, 2, 2, 3, 3};
  // 使用 std::unique
  auto newEnd = std::unique(src.begin(), src.end());
  fmt::println("std::unique: {}", std::vector<int>(src.begin(), newEnd));
  // 预期输出: std::unique: [1, 2, 3]

  src = {1, 1, 2, 2, 3, 3};
  // 使用 std::ranges::unique
  auto result = std::ranges::unique(src);
  src.erase(result.begin(), result.end());
  fmt::println("std::ranges::unique: {}", src);
  // 预期输出: std::ranges::unique: [1, 2, 3]
}

// 示例 6: unique_copy, ranges::unique_copy
void example_unique_copy() {
  std::vector<int> src = {1, 1, 2, 2, 3, 3};
  std::vector<int> result;
  // 使用 std::unique_copy
  std::unique_copy(src.begin(), src.end(), std::back_inserter(result));
  fmt::println("std::unique_copy: {}", result);
  // 预期输出: std::unique_copy: [1, 2, 3]

  src = {1, 1, 2, 2, 3, 3};
  result.clear();
  // 使用 std::ranges::unique_copy
  std::ranges::unique_copy(src, std::back_inserter(result));
  fmt::println("std::ranges::unique_copy: {}", result);
  // 预期输出: std::ranges::unique_copy: [1, 2, 3]
}

int main() {
  example_remove();
  example_remove_if();
  example_remove_copy();
  example_remove_copy_if();
  example_unique();
  example_unique_copy();
  return 0;
}
