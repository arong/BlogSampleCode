#include <fmt/ranges.h>

#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

// 示例 1: push_heap, ranges::push_heap
void example_push_heap() {
  std::vector<int> heap = {3, 1, 2};
  // 先将范围转换为堆
  std::make_heap(heap.begin(), heap.end());
  // 插入新元素
  heap.push_back(4);
  // 使用 std::push_heap
  std::push_heap(heap.begin(), heap.end());
  fmt::println("std::push_heap: {}", heap);
  // 预期输出: std::push_heap: [4, 3, 2, 1]

  heap = {3, 1, 2};
  std::ranges::make_heap(heap);
  heap.push_back(4);
  // 使用 std::ranges::push_heap
  std::ranges::push_heap(heap);
  fmt::println("std::ranges::push_heap: {}", heap);
  // 预期输出: std::ranges::push_heap: [4, 3, 2, 1]
}

// 示例 2: pop_heap, ranges::pop_heap
void example_pop_heap() {
  std::vector<int> heap = {4, 3, 2, 1};
  // 使用 std::pop_heap
  std::pop_heap(heap.begin(), heap.end());
  int popped = heap.back();
  heap.pop_back();
  fmt::println("std::pop_heap popped: {}, remaining: {}", popped, heap);
  // 预期输出: std::pop_heap popped: 4, remaining: [3, 1, 2]

  heap = {4, 3, 2, 1};
  // 使用 std::ranges::pop_heap
  std::ranges::pop_heap(heap);
  popped = heap.back();
  heap.pop_back();
  fmt::println("std::ranges::pop_heap popped: {}, remaining: {}", popped, heap);
  // 预期输出: std::ranges::pop_heap popped: 4, remaining: [3, 1, 2]
}

// 示例 3: make_heap, ranges::make_heap
void example_make_heap() {
  std::vector<int> numbers = {3, 1, 2};
  // 使用 std::make_heap
  std::make_heap(numbers.begin(), numbers.end());
  fmt::println("std::make_heap: {}", numbers);
  // 预期输出: std::make_heap: [3, 1, 2]（可能形式，堆结构不唯一）

  numbers = {3, 1, 2};
  // 使用 std::ranges::make_heap
  std::ranges::make_heap(numbers);
  fmt::println("std::ranges::make_heap: {}", numbers);
  // 预期输出: std::ranges::make_heap: [3, 1, 2]（可能形式，堆结构不唯一）
}

// 示例 4: sort_heap, ranges::sort_heap
void example_sort_heap() {
  std::vector<int> heap = {4, 3, 2, 1};
  // 使用 std::sort_heap
  std::sort_heap(heap.begin(), heap.end());
  fmt::println("std::sort_heap: {}", heap);
  // 预期输出: std::sort_heap: [1, 2, 3, 4]

  heap = {4, 3, 2, 1};
  // 使用 std::ranges::sort_heap
  std::ranges::sort_heap(heap);
  fmt::println("std::ranges::sort_heap: {}", heap);
  // 预期输出: std::ranges::sort_heap: [1, 2, 3, 4]
}

// 示例 5: is_heap, ranges::is_heap
void example_is_heap() {
  std::vector<int> heap = {4, 3, 2, 1};
  // 使用 std::is_heap
  bool stdIsHeap = std::is_heap(heap.begin(), heap.end());
  fmt::println("std::is_heap: {}", stdIsHeap);
  // 预期输出: std::is_heap: true

  std::vector<int> notHeap = {1, 3, 2, 4};
  stdIsHeap = std::is_heap(notHeap.begin(), notHeap.end());
  fmt::println("std::is_heap (not heap): {}", stdIsHeap);
  // 预期输出: std::is_heap (not heap): false

  heap = {4, 3, 2, 1};
  // 使用 std::ranges::is_heap
  bool rangesIsHeap = std::ranges::is_heap(heap);
  fmt::println("std::ranges::is_heap: {}", rangesIsHeap);
  // 预期输出: std::ranges::is_heap: true

  notHeap = {1, 3, 2, 4};
  rangesIsHeap = std::ranges::is_heap(notHeap);
  fmt::println("std::ranges::is_heap (not heap): {}", rangesIsHeap);
  // 预期输出: std::ranges::is_heap (not heap): false
}

// 示例 6: is_heap_until, ranges::is_heap_until
void example_is_heap_until() {
  std::vector<int> partialHeap = {4, 3, 1, 2, 5};
  // 使用 std::is_heap_until
  auto stdHeapUntil =
      std::is_heap_until(partialHeap.begin(), partialHeap.end());
  fmt::println("std::is_heap_until: {}",
               std::distance(partialHeap.begin(), stdHeapUntil));
  // 预期输出: std::is_heap_until: 3

  partialHeap = {4, 3, 1, 2, 5};
  // 使用 std::ranges::is_heap_until
  auto rangesHeapUntil = std::ranges::is_heap_until(partialHeap);
  fmt::println("std::ranges::is_heap_until: {}",
               std::distance(partialHeap.begin(), rangesHeapUntil));
  // 预期输出: std::ranges::is_heap_until: 3
}

int main() {
  example_push_heap();
  example_pop_heap();
  example_make_heap();
  example_sort_heap();
  example_is_heap();
  example_is_heap_until();
  return 0;
}
