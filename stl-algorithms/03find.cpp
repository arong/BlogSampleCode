#include <fmt/core.h>

#include <algorithm>
#include <vector>

void Contains() {
  std::vector v = {1, 2, 3, 4, 5, 3};
  // ranges::contains (C++23)
  fmt::print("Vector contains 3: {}\n", std::ranges::contains(v, 3));
  // Vector contains 3: true
}

void ContainsSubrange() {
  std::vector<int> v = {1, 2, 3, 4, 5, 3};
  std::vector<int> sub_v = {3, 4};

  // ranges::contains_subrange (C++23)
  fmt::print("Vector contains sub - range {{3, 4}}: {}\n",
             std::ranges::contains_subrange(v, sub_v));
  // Vector contains sub - range {3, 4}: true
}

void Find() {
  std::vector<int> v = {1, 2, 3, 4, 5, 3};

  // find
  if (auto it = std::find(v.begin(), v.end(), 3); it != v.end()) {
    fmt::print("Found 3 at position: {}\n", std::distance(v.begin(), it));
    // Found 3 at position: 2
  }
  // ranges::find
  if (auto rit = std::ranges::find(v, 3); rit != v.end()) {
    fmt::print("Found 3 at position (ranges): {}\n",
               std::distance(v.begin(), rit));
    // Found 3 at position (ranges): 2
  }
}

void FindIf() {
  std::vector<int> v = {1, 2, 3, 4, 5, 3};

  // find_if
  // 查找第一个大于 3 的元素，第一个大于 3 的元素是 4，其位置索引是 3
  if (auto it_if =
          std::find_if(v.begin(), v.end(), [](int n) { return n > 3; });
      it_if != v.end()) {
    fmt::print("Found element greater than 3 at position: {}\n",
               std::distance(v.begin(), it_if));
    // Found element greater than 3 at position: 3
  }

  // ranges::find_if
  // 使用 ranges 版本查找第一个大于 3 的元素，结果位置索引同样是 3
  if (auto rit_if = std::ranges::find_if(v, [](int n) { return n > 3; });
      rit_if != v.end()) {
    fmt::print("Found element greater than 3 at position (ranges): {}\n",
               std::distance(v.begin(), rit_if));
    // Found element greater than 3 at position (ranges): 3
  }
}

void FindIfNot() {
  std::vector<int> v = {1, 2, 3, 4, 5, 3};
  // find_if_not
  // 查找第一个不大于 3 的元素，也就是第一个小于等于 3 的元素，是 1，位置索引是0
  if (auto it_if_not =
          std::find_if_not(v.begin(), v.end(), [](int n) { return n > 3; });
      it_if_not != v.end()) {
    fmt::print("Found element not greater than 3 at position: {}\n",
               std::distance(v.begin(), it_if_not));
    // Found element not greater than 3 at position: 0
  }

  // ranges::find_if_not
  // 使用 ranges 版本查找第一个不大于 3 的元素，结果位置索引还是 0
  if (auto rit_if_not =
          std::ranges::find_if_not(v, [](int n) { return n > 3; });
      rit_if_not != v.end()) {
    fmt::print("Found element not greater than 3 at position (ranges): {}\n",
               std::distance(v.begin(), rit_if_not));
    // Found element not greater than 3 at position (ranges): 0
  }
}

void example_ranges_find_last() {
  std::vector<int> numbers = {1, 2, 3, 2, 4, 2};
  int target = 2;
  auto result = std::ranges::find_last(numbers, target);
  if (result.begin() != numbers.end()) {
    fmt::println("ranges::find_last: Found 2 at index {}",
                 std::distance(numbers.begin(), result.begin()));
  } else {
    fmt::println("ranges::find_last: Not found");
  }
}

// 示例 2: ranges::find_last_if (C++23)
void example_ranges_find_last_if() {
  std::vector<int> numbers = {1, 2, 3, 4, 5, 6};
  auto isEven = [](int num) { return num % 2 == 0; };
  auto result = std::ranges::find_last_if(numbers, isEven);
  if (result.begin() != numbers.end()) {
    fmt::println("ranges::find_last_if: Found last even number {} at index {}",
                 *result.begin(),
                 std::distance(numbers.begin(), result.begin()));
    // 预期输出: ranges::find_last_if: Found even number 6 at index 5
  } else {
    fmt::println("ranges::find_last_if: Not found");
  }
}

// 示例 3: ranges::find_last_if_not (C++23)
void example_ranges_find_last_if_not() {
  std::vector<int> numbers = {2, 4, 6, 3, 8, 10};
  auto isEven = [](int num) { return num % 2 == 0; };
  auto result = std::ranges::find_last_if_not(numbers, isEven);
  if (result.begin() != numbers.end()) {
    fmt::println("ranges::find_last_if_not: Found odd number {} at index {}",
                 *result.begin(),
                 std::distance(numbers.begin(), result.begin()));
    // 预期输出: ranges::find_last_if_not: Found odd number 3 at index 3
  } else {
    fmt::println("ranges::find_last_if_not: Not found");
  }
}

// 示例 4: find_end, ranges::find_end
void example_find_end() {
  std::vector<int> mainRange = {1, 2, 3, 4, 1, 2, 3};
  std::vector<int> subRange = {1, 2, 3};
  // 使用 std::find_end
  auto stdResult = std::find_end(mainRange.begin(), mainRange.end(),
                                 subRange.begin(), subRange.end());
  if (stdResult != mainRange.end()) {
    fmt::println("std::find_end: Sub - range found starting at index {}",
                 std::distance(mainRange.begin(), stdResult));
    // 预期输出: std::find_end: Sub - range found starting at index 4
  } else {
    fmt::println("std::find_end: Sub - range not found");
  }

  // 使用 std::ranges::find_end
  auto rangesResult = std::ranges::find_end(mainRange, subRange);
  if (!rangesResult.empty()) {
    fmt::println(
        "std::ranges::find_end: Sub - range found starting at index {}",
        std::distance(mainRange.begin(), rangesResult.begin()));
    // 预期输出: std::ranges::find_end: Sub - range found starting at index 4
  } else {
    fmt::println("std::ranges::find_end: Sub - range not found");
  }
}

// 示例 5: find_first_of, ranges::find_first_of
void example_find_first_of() {
  std::vector<int> firstRange = {1, 2, 3, 4, 5};
  std::vector<int> secondRange = {3, 6, 7};
  // 使用 std::find_first_of
  auto stdResult = std::find_first_of(firstRange.begin(), firstRange.end(),
                                      secondRange.begin(), secondRange.end());
  if (stdResult != firstRange.end()) {
    fmt::println("std::find_first_of: Found matching element {} at index {}",
                 *stdResult, std::distance(firstRange.begin(), stdResult));
    // 预期输出: std::find_first_of: Found matching element 3 at index 2
  } else {
    fmt::println("std::find_first_of: No matching element found");
  }

  // 使用 std::ranges::find_first_of
  auto rangesResult = std::ranges::find_first_of(firstRange, secondRange);
  if (rangesResult != firstRange.end()) {
    fmt::println(
        "std::ranges::find_first_of: Found matching element {} at index {}",
        *rangesResult, std::distance(firstRange.begin(), rangesResult));
    // 预期输出: std::ranges::find_first_of: Found matching element 3 at index 2
  } else {
    fmt::println("std::ranges::find_first_of: No matching element found");
  }
}

// 示例 6: adjacent_find, ranges::adjacent_find
void example_adjacent_find() {
  std::vector<int> numbers = {1, 2, 2, 3, 4};
  // 使用 std::adjacent_find
  auto stdResult = std::adjacent_find(numbers.begin(), numbers.end());
  if (stdResult != numbers.end()) {
    fmt::println(
        "std::adjacent_find: Adjacent equal elements {} found at index {}",
        *stdResult, std::distance(numbers.begin(), stdResult));
    // 预期输出: std::adjacent_find: Adjacent equal elements 2 found at index 1
  } else {
    fmt::println("std::adjacent_find: No adjacent equal elements found");
  }

  // 使用 std::ranges::adjacent_find
  auto rangesResult = std::ranges::adjacent_find(numbers);
  if (rangesResult != numbers.end()) {
    fmt::println(
        "std::ranges::adjacent_find: Adjacent equal elements {} found at index "
        "{}",
        *rangesResult, std::distance(numbers.begin(), rangesResult));
    // 预期输出: std::ranges::adjacent_find: Adjacent equal elements 2 found at
    // index 1
  } else {
    fmt::println(
        "std::ranges::adjacent_find: No adjacent equal elements found");
  }
}

void FindAdjacent() {
  std::vector<int> v = {1, 2, 3, 4, 5, 3};

  // adjacent_find
  // 查找相邻且相等的元素，向量中没有相邻且相等的元素，所以此条件不满足，不会有输出
  if (auto it_adj = std::adjacent_find(v.begin(), v.end()); it_adj != v.end()) {
    fmt::print("Found adjacent equal elements at position: {}\n",
               std::distance(v.begin(), it_adj));
  }

  // ranges::adjacent_find
  // 使用 ranges 版本查找相邻且相等的元素，同样不会有输出
  if (auto rit_adj = std::ranges::adjacent_find(v); rit_adj != v.end()) {
    fmt::print("Found adjacent equal elements at position (ranges): {}\n",
               std::distance(v.begin(), rit_adj));
  }
}

int main() {
  Contains();
  ContainsSubrange();
  Find();
  FindIf();
  FindIfNot();
  FindAdjacent();
  example_ranges_find_last();
  example_ranges_find_last_if();
  example_ranges_find_last_if_not();
  example_find_end();
  example_find_first_of();
  example_adjacent_find();
  return 0;
}
