#include <fmt/ranges.h>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>

// 示例 1: iota, ranges::iota
void example_iota() {
  std::vector<int> numbers(5);
  // 使用 std::iota
  std::iota(numbers.begin(), numbers.end(), 1);
  fmt::println("std::iota: {}", numbers);
  // 输出: std::iota: [1, 2, 3, 4, 5]

  numbers.resize(5);
  // 使用 std::ranges::iota
  std::ranges::iota(numbers, 1);
  fmt::println("std::ranges::iota: {}", numbers);
  // 输出: std::ranges::iota: [1, 2, 3, 4, 5]
}

// 示例 2: accumulate
void example_accumulate() {
  std::vector<int> numbers = {1, 2, 3, 4, 5};
  // 使用 std::accumulate
  int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
  fmt::println("std::accumulate: {}", sum);
  // 输出: std::accumulate: 15
}

// 示例 3: inner_product
void example_inner_product() {
  std::vector<int> first = {1, 2, 3};
  std::vector<int> second = {4, 5, 6};
  // 使用 std::inner_product
  int product =
      std::inner_product(first.begin(), first.end(), second.begin(), 0);
  fmt::println("std::inner_product: {}", product);
  // 输出: std::inner_product: 32
}

// 示例 4: adjacent_difference
void example_adjacent_difference() {
  std::vector<int> numbers = {1, 3, 6, 10, 15};
  std::vector<int> result(5);
  // 使用 std::adjacent_difference
  std::adjacent_difference(numbers.begin(), numbers.end(), result.begin());
  fmt::println("std::adjacent_difference: {}", result);
  // 输出: std::adjacent_difference: [1, 2, 3, 4, 5]
}

// 示例 5: partial_sum
void example_partial_sum() {
  std::vector<int> numbers = {1, 2, 3, 4, 5};
  std::vector<int> result(5);
  // 使用 std::partial_sum
  std::partial_sum(numbers.begin(), numbers.end(), result.begin());
  fmt::println("std::partial_sum: {}", result);
  // 输出: std::partial_sum: [1, 3, 6, 10, 15]
}

// 示例 6: reduce (C++17)
void example_reduce() {
  std::vector<int> numbers = {1, 2, 3, 4, 5};
  // 使用 std::reduce
  int sum = std::reduce(numbers.begin(), numbers.end(), 0);
  fmt::println("std::reduce: {}", sum);
  // 输出: std::reduce: 15
}

// 示例 7: inclusive_scan
void example_inclusive_scan() {
  std::vector<int> numbers = {1, 2, 3, 4, 5};
  std::vector<int> result(5);
  // 使用 std::inclusive_scan
  std::inclusive_scan(numbers.begin(), numbers.end(), result.begin());
  fmt::println("std::inclusive_scan: {}", result);
  // 输出: std::inclusive_scan: [1, 3, 6, 10, 15]
}

// 示例 8: exclusive_scan
void example_exclusive_scan() {
  std::vector<int> numbers = {1, 2, 3, 4, 5};
  std::vector<int> result(5);
  // 使用 std::exclusive_scan
  std::exclusive_scan(numbers.begin(), numbers.end(), result.begin(), 0);
  fmt::println("std::exclusive_scan: {}", result);
  // 输出: std::exclusive_scan: [0, 1, 3, 6, 10]
}

// 示例 9: transform_reduce
void example_transform_reduce() {
  std::vector<int> numbers = {1, 2, 3, 4, 5};
  auto square = [](int x) { return x * x; };
  // 使用 std::transform_reduce
  int sumOfSquares = std::transform_reduce(numbers.begin(), numbers.end(), 0,
                                           std::plus<>(), square);
  fmt::println("std::transform_reduce: {}", sumOfSquares);
  // 输出: std::transform_reduce: 55
}

// 示例 10: transform_inclusive_scan
void example_transform_inclusive_scan() {
  std::vector<int> numbers = {1, 2, 3, 4, 5};
  std::vector<int> result(5);
  auto square = [](int x) { return x * x; };
  // 使用 std::transform_inclusive_scan
  std::transform_inclusive_scan(numbers.begin(), numbers.end(), result.begin(),
                                std::plus<>(), square);
  fmt::println("std::transform_inclusive_scan: {}", result);
  // 输出: std::transform_inclusive_scan: [1, 5, 14, 30, 55]
}

// 示例 11: transform_exclusive_scan
void example_transform_exclusive_scan() {
  std::vector<int> numbers = {1, 2, 3, 4, 5};
  std::vector<int> result(5);
  auto square = [](int x) { return x * x; };
  // 使用 std::transform_exclusive_scan
  std::transform_exclusive_scan(numbers.begin(), numbers.end(), result.begin(),
                                0, std::plus<>(), square);
  fmt::println("std::transform_exclusive_scan: {}", result);
  // 输出: std::transform_exclusive_scan: [0, 1, 5, 14, 30]
}

int main() {
  example_iota();
  example_accumulate();
  example_inner_product();
  example_adjacent_difference();
  example_partial_sum();
  example_reduce();
  example_inclusive_scan();
  example_exclusive_scan();
  example_transform_reduce();
  example_transform_inclusive_scan();
  example_transform_exclusive_scan();
  return 0;
}
