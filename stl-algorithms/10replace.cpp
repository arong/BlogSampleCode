#include <fmt/ranges.h>

#include <algorithm>
#include <vector>

// 示例 1: replace, ranges::replace
void example_replace() {
  std::vector v = {1, 2, 3, 2, 4, 2};
  // 使用 std::replace
  std::replace(v.begin(), v.end(), 2, 9);
  fmt::println("std::replace: {}", v);
  // 预期输出: std::replace: [1, 9, 3, 9, 4, 9]

  v = {1, 2, 3, 2, 4, 2};
  // 使用 std::ranges::replace
  std::ranges::replace(v, 2, 9);
  fmt::println("std::ranges::replace: {}", v);
  // 预期输出: std::ranges::replace: [1, 9, 3, 9, 4, 9]
}

// 示例 2: replace_if, ranges::replace_if
void example_replace_if() {
  std::vector v = {1, 2, 3, 4, 5, 6};
  auto is_odd = [](int num) { return num % 2 == 0; };
  // 使用 std::replace_if
  std::replace_if(v.begin(), v.end(), is_odd, 0);
  fmt::println("std::replace_if: {}", v);
  // 预期输出: std::replace_if: [1, 0, 3, 0, 5, 0]

  v = {1, 2, 3, 4, 5, 6};
  // 使用 std::ranges::replace_if
  std::ranges::replace_if(v, is_odd, 0);
  fmt::println("std::ranges::replace_if: {}", v);
  // 预期输出: std::ranges::replace_if: [1, 0, 3, 0, 5, 0]
}

// 示例 3: replace_copy, ranges::replace_copy
void example_replace_copy() {
  std::vector v = {1, 2, 3, 2, 4, 2};
  std::vector<int> result(v.size());
  // 使用 std::replace_copy
  std::replace_copy(v.begin(), v.end(), result.begin(), 2, 9);
  fmt::println("std::replace_copy: {}", result);
  // 预期输出: std::replace_copy: [1, 9, 3, 9, 4, 9]

  v = {1, 2, 3, 2, 4, 2};
  result.clear();
  result.resize(v.size());
  // 使用 std::ranges::replace_copy
  std::ranges::replace_copy(v, result.begin(), 2, 9);
  fmt::println("std::ranges::replace_copy: {}", result);
  // 预期输出: std::ranges::replace_copy: [1, 9, 3, 9, 4, 9]
}

// 示例 4: replace_copy_if, ranges::replace_copy_if
void example_replace_copy_if() {
  std::vector<int> v = {1, 2, 3, 4, 5, 6};
  std::vector<int> result(v.size());
  // 使用 std::replace_copy_if
  std::replace_copy_if(
      v.begin(), v.end(), result.begin(), [](int num) { return num % 2 == 0; },
      0);
  fmt::println("std::replace_copy_if: {}", result);
  // 预期输出: std::replace_copy_if: [1, 0, 3, 0, 5, 0]

  v = {1, 2, 3, 4, 5, 6};
  result.clear();
  result.resize(v.size());
  // 使用 std::ranges::replace_copy_if
  std::ranges::replace_copy_if(
      v, result.begin(), [](int num) { return num % 2 == 0; }, 0);
  fmt::println("std::ranges::replace_copy_if: {}", result);
  // 预期输出: std::ranges::replace_copy_if: [1, 0, 3, 0, 5, 0]
}

int main() {
  example_replace();
  example_replace_if();
  example_replace_copy();
  example_replace_copy_if();
  return 0;
}
