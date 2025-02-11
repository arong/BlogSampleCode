#include <fmt/ranges.h>

#include <algorithm>
#include <ranges>
#include <vector>

// 示例 1: is_partitioned, ranges::is_partitioned
void example_is_partitioned() {
  std::vector v = {1, 3, 5, 2, 4, 6};
  auto is_even = [](int num) { return num % 2 == 0; };
  // 使用 std::is_partitioned
  bool stdIsPartitioned = std::is_partitioned(v.begin(), v.end(), is_even);
  fmt::println("std::is_partitioned: {}", stdIsPartitioned);
  // 预期输出: std::is_partitioned: false

  v = {2, 4, 6, 1, 3, 5};
  // 使用 std::ranges::is_partitioned
  bool rangesIsPartitioned = std::ranges::is_partitioned(v, is_even);
  fmt::println("std::ranges::is_partitioned: {}", rangesIsPartitioned);
  // 预期输出: std::ranges::is_partitioned: true
}

// 示例 2: partition, ranges::partition
void example_partition() {
  std::vector v = {1, 2, 3, 4, 5, 6};
  auto is_even = [](int num) { return num % 2 == 0; };
  // 使用 std::partition
  auto stdPartitionEnd = std::partition(v.begin(), v.end(), is_even);
  fmt::println("std::partition: {}",
               std::vector<int>(v.begin(), stdPartitionEnd));
  // 预期输出: 满足条件的元素组成的向量（顺序可能不同）
  fmt::println("std::partition rest: {}",
               std::vector<int>(stdPartitionEnd, v.end()));
  // 预期输出: 不满足条件的元素组成的向量（顺序可能不同）

  v = {1, 2, 3, 4, 5, 6};
  // 使用 std::ranges::partition
  auto result = std::ranges::partition(v, is_even);
  fmt::println("std::ranges::partition: {}",
               std::vector<int>(v.begin(), result.begin()));
  // 预期输出: 满足条件的元素组成的向量（顺序可能不同）
  fmt::println("std::ranges::partition rest: {}",
               std::vector<int>(result.begin(), v.end()));
  // 预期输出: 不满足条件的元素组成的向量（顺序可能不同）
}

// 示例 3: partition_copy, ranges::partition_copy
void example_partition_copy() {
  std::vector<int> v = {1, 2, 3, 4, 5, 6};
  std::vector<int> trueResult, falseResult;
  auto is_even = [](int num) { return num % 2 == 0; };
  // 使用 std::partition_copy
  std::partition_copy(v.begin(), v.end(), std::back_inserter(trueResult),
                      std::back_inserter(falseResult), is_even);
  fmt::println("std::partition_copy true: {}", trueResult);
  // 预期输出: 满足条件的元素组成的向量
  fmt::println("std::partition_copy false: {}", falseResult);
  // 预期输出: 不满足条件的元素组成的向量

  v = {1, 2, 3, 4, 5, 6};
  trueResult.clear();
  falseResult.clear();
  // 使用 std::ranges::partition_copy
  std::ranges::partition_copy(v, std::back_inserter(trueResult),
                              std::back_inserter(falseResult), is_even);
  fmt::println("std::ranges::partition_copy true: {}", trueResult);
  // 预期输出: 满足条件的元素组成的向量
  fmt::println("std::ranges::partition_copy false: {}", falseResult);
  // 预期输出: 不满足条件的元素组成的向量
}

// 示例 4: stable_partition, ranges::stable_partition
void example_stable_partition() {
  std::vector v = {1, 2, 3, 4, 5, 6};
  auto is_even = [](int num) { return num % 2 == 0; };
  // 使用 std::stable_partition
  auto stdStablePartitionEnd =
      std::stable_partition(v.begin(), v.end(), is_even);
  fmt::println("std::stable_partition: {}",
               std::vector<int>(v.begin(), stdStablePartitionEnd));
  // 预期输出: 满足条件的元素组成的向量（保持相对顺序）
  fmt::println("std::stable_partition rest: {}",
               std::vector<int>(stdStablePartitionEnd, v.end()));
  // 预期输出: 不满足条件的元素组成的向量（保持相对顺序）

  v = {1, 2, 3, 4, 5, 6};
  // 使用 std::ranges::stable_partition
  auto rangesStablePartitionResult = std::ranges::stable_partition(v, is_even);
  fmt::println(
      "std::ranges::stable_partition: {}",
      std::vector<int>(v.begin(), rangesStablePartitionResult.begin()));
  // 预期输出: 满足条件的元素组成的向量（保持相对顺序）
  fmt::println("std::ranges::stable_partition rest: {}",
               std::vector<int>(rangesStablePartitionResult.begin(), v.end()));
  // 预期输出: 不满足条件的元素组成的向量（保持相对顺序）
}

// 示例 5: partition_point, ranges::partition_point
void example_partition_point() {
  std::vector v = {2, 4, 6, 1, 3, 5};
  auto is_even = [](int num) { return num % 2 == 0; };
  // 使用 std::partition_point
  auto stdPartitionPoint = std::partition_point(v.begin(), v.end(), is_even);
  fmt::println("std::partition_point: {}", *stdPartitionPoint);
  // 预期输出: 分区点的元素值，这里是 1

  v = {2, 4, 6, 1, 3, 5};
  // 使用 std::ranges::partition_point
  auto rangesPartitionPoint = std::ranges::partition_point(v, is_even);
  fmt::println("std::ranges::partition_point: {}", *rangesPartitionPoint);
  // 预期输出: 分区点的元素值，这里是 1
}

int main() {
  example_is_partitioned();
  example_partition();
  example_partition_copy();
  example_stable_partition();
  example_partition_point();
  return 0;
}
