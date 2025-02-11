#include <fmt/core.h>
#include <fmt/ranges.h>

#include <algorithm>
#include <vector>

// 示例 1: next_permutation, ranges::next_permutation
void example_next_permutation() {
  std::vector<int> numbers = {1, 2, 3};
  // 使用 std::next_permutation
  bool stdHasNext = std::next_permutation(numbers.begin(), numbers.end());
  fmt::println("std::next_permutation: has next = {}, permutation = {}",
               stdHasNext, numbers);
  fmt::println("std::next_permutation: permutation = {}", numbers);
  // 预期输出: std::next_permutation: has next = true, permutation = [1, 3, 2]

  numbers = {1, 2, 3};
  // 使用 std::ranges::next_permutation
  auto rangesResult = std::ranges::next_permutation(numbers);
  fmt::println("std::ranges::next_permutation: has next = {}, permutation ={}",
               rangesResult.found, numbers);
  // 预期输出: std::ranges::next_permutation: has next = true, permutation = [1,
  // 3, 2]
}

// 示例 2: prev_permutation, ranges::prev_permutation
void example_prev_permutation() {
  std::vector<int> numbers = {3, 2, 1};
  // 使用 std::prev_permutation
  bool stdHasPrev = std::prev_permutation(numbers.begin(), numbers.end());
  fmt::println("std::prev_permutation: has prev = {}, permutation = {}",
               stdHasPrev, numbers);
  // 预期输出: std::prev_permutation: has prev = true, permutation = [3, 1, 2]

  numbers = {3, 2, 1};
  // 使用 std::ranges::prev_permutation
  auto rangesResult = std::ranges::prev_permutation(numbers);
  fmt::println("std::ranges::prev_permutation: has prev = {}, permutation = {}",
               rangesResult.found, numbers);
  // 预期输出: std::ranges::prev_permutation: has prev = true, permutation = [3,
  // 1, 2]
}

// 示例 3: is_permutation, ranges::is_permutation
void example_is_permutation() {
  std::vector<int> first = {1, 2, 3};
  std::vector<int> second = {3, 2, 1};
  // 使用 std::is_permutation
  bool stdIsPerm =
      std::is_permutation(first.begin(), first.end(), second.begin());
  fmt::println("std::is_permutation: {}", stdIsPerm);
  // 预期输出: std::is_permutation: true

  first = {1, 2, 3};
  second = {3, 2, 1};
  // 使用 std::ranges::is_permutation
  bool rangesIsPerm = std::ranges::is_permutation(first, second);
  fmt::println("std::ranges::is_permutation: {}", rangesIsPerm);
  // 预期输出: std::ranges::is_permutation: true
}

int main() {
  example_next_permutation();
  example_prev_permutation();
  example_is_permutation();
  return 0;
}
