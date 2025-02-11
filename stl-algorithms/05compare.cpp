#include <fmt/ranges.h>

#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

// 示例 1: mismatch, ranges::mismatch
void example_mismatch() {
  std::vector<int> first = {1, 2, 3, 4, 5};
  std::vector<int> second = {1, 2, 6, 4, 5};

  // 使用 std::mismatch
  auto stdMismatch = std::mismatch(first.begin(), first.end(), second.begin());
  if (stdMismatch.first != first.end()) {
    fmt::println("std::mismatch: First mismatch at index {}, values: {} and {}",
                 std::distance(first.begin(), stdMismatch.first),
                 *stdMismatch.first, *stdMismatch.second);
    // 预期输出: std::mismatch: First mismatch at index 2, values: 3 and 6
  } else {
    fmt::println("std::mismatch: No mismatch found");
  }

  // 使用 std::ranges::mismatch
  auto rangesMismatch = std::ranges::mismatch(first, second);
  if (rangesMismatch.in1 != first.end()) {
    fmt::println(
        "std::ranges::mismatch: First mismatch at index {}, values: {} and {}",
        std::distance(first.begin(), rangesMismatch.in1), *rangesMismatch.in1,
        *rangesMismatch.in2);
    // 预期输出: std::ranges::mismatch: First mismatch at index 2, values: 3 and
    // 6
  } else {
    fmt::println("std::ranges::mismatch: No mismatch found");
  }
}

// 示例 2: equal, ranges::equal
void example_equal() {
  std::vector<int> first = {1, 2, 3};
  std::vector<int> second = {1, 2, 3};

  // 使用 std::equal
  bool stdEqual = std::equal(first.begin(), first.end(), second.begin());
  fmt::println("std::equal: {}", stdEqual);
  // 预期输出: std::equal: true

  std::vector<int> third = {1, 2, 4};
  stdEqual = std::equal(first.begin(), first.end(), third.begin());
  fmt::println("std::equal (different): {}", stdEqual);
  // 预期输出: std::equal (different): false

  // 使用 std::ranges::equal
  bool rangesEqual = std::ranges::equal(first, second);
  fmt::println("std::ranges::equal: {}", rangesEqual);
  // 预期输出: std::ranges::equal: true

  rangesEqual = std::ranges::equal(first, third);
  fmt::println("std::ranges::equal (different): {}", rangesEqual);
  // 预期输出: std::ranges::equal (different): false
}

// 示例 3: search, ranges::search
void example_search() {
  std::vector<int> mainRange = {1, 2, 3, 4, 5, 1, 2, 3};
  std::vector<int> subRange = {1, 2, 3};

  // 使用 std::search
  auto stdSearch = std::search(mainRange.begin(), mainRange.end(),
                               subRange.begin(), subRange.end());
  if (stdSearch != mainRange.end()) {
    fmt::println("std::search: Sub - range found starting at index {}",
                 std::distance(mainRange.begin(), stdSearch));
    // 预期输出: std::search: Sub - range found starting at index 0
  } else {
    fmt::println("std::search: Sub - range not found");
  }

  // 使用 std::ranges::search
  auto rangesSearch = std::ranges::search(mainRange, subRange);
  if (rangesSearch.begin() != mainRange.end()) {
    fmt::println("std::ranges::search: Sub - range found starting at index {}",
                 std::distance(mainRange.begin(), rangesSearch.begin()));
    // 预期输出: std::ranges::search: Sub - range found starting at index 0
  } else {
    fmt::println("std::ranges::search: Sub - range not found");
  }
}

// 示例 4: search_n, ranges::search_n
void example_search_n() {
  std::vector<int> numbers = {1, 2, 2, 2, 3, 4};
  int value = 2;
  int count = 3;

  // 使用 std::search_n
  auto stdSearchN = std::search_n(numbers.begin(), numbers.end(), count, value);
  if (stdSearchN != numbers.end()) {
    fmt::println("std::search_n: Sequence of {} {}s found starting at index {}",
                 count, value, std::distance(numbers.begin(), stdSearchN));
    // 预期输出: std::search_n: Sequence of 3 2s found starting at index 1
  } else {
    fmt::println("std::search_n: Sequence not found");
  }

  // 使用 std::ranges::search_n
  auto rangesSearchN = std::ranges::search_n(numbers, count, value);
  if (rangesSearchN.begin() != numbers.end()) {
    fmt::println(
        "std::ranges::search_n: Sequence of {} {}s found starting at index {}",
        count, value, std::distance(numbers.begin(), rangesSearchN.begin()));
    // 预期输出: std::ranges::search_n: Sequence of 3 2s found starting at index
    // 1
  } else {
    fmt::println("std::ranges::search_n: Sequence not found");
  }
}

// 示例 5: ranges::starts_with
void example_ranges_starts_with() {
#ifdef _MSC_VER
  std::vector<int> mainRange = {1, 2, 3, 4, 5};
  std::vector<int> startRange = {1, 2, 3};

  bool startsWith = std::ranges::starts_with(mainRange, startRange);
  fmt::println("std::ranges::starts_with: {}", startsWith);
  // 预期输出: std::ranges::starts_with: true

  std::vector<int> wrongStartRange = {2, 3, 4};
  startsWith = std::ranges::starts_with(mainRange, wrongStartRange);
  fmt::println("std::ranges::starts_with (wrong): {}", startsWith);
// 预期输出: std::ranges::starts_with (wrong): false
#endif
}

// 示例 6: ranges::ends_with
void example_ranges_ends_with() {
#ifdef _MSC_VER
  std::vector<int> mainRange = {1, 2, 3, 4, 5};
  std::vector<int> endRange = {3, 4, 5};

  bool endsWith = std::ranges::ends_with(mainRange, endRange);
  fmt::println("std::ranges::ends_with: {}", endsWith);
  // 预期输出: std::ranges::ends_with: true

  std::vector<int> wrongEndRange = {4, 5, 6};
  endsWith = std::ranges::ends_with(mainRange, wrongEndRange);
  fmt::println("std::ranges::ends_with (wrong): {}", endsWith);
// 预期输出: std::ranges::ends_with (wrong): false
#endif
}

int main() {
  example_mismatch();
  example_equal();
  example_search();
  example_search_n();
  example_ranges_starts_with();
  example_ranges_ends_with();
  return 0;
}
