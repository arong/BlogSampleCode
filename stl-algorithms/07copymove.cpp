#include <fmt/ranges.h>

#include <algorithm>
#include <ranges>
#include <vector>

// 示例 1: copy, ranges::copy
void example_copy() {
  std::vector source = {1, 2, 3, 4, 5};
  std::vector<int> destination(5);

  // 使用 std::copy
  std::copy(source.begin(), source.end(), destination.begin());
  fmt::println("std::copy: {}", destination);
  // 预期输出: std::copy: [1, 2, 3, 4, 5]

  source = {1, 2, 3, 4, 5};
  destination.resize(5);
  // 使用 std::ranges::copy
  std::ranges::copy(source, destination.begin());
  fmt::println("std::ranges::copy: {}", destination);
  // 预期输出: std::ranges::copy: [1, 2, 3, 4, 5]
}

// 示例 2: copy_if, ranges::copy_if
void example_copy_if() {
  std::vector source = {1, 2, 3, 4, 5};
  std::vector<int> destination;
  auto isEven = [](int num) { return num % 2 == 0; };

  // 使用 std::copy_if
  std::copy_if(source.begin(), source.end(), std::back_inserter(destination),
               isEven);
  fmt::println("std::copy_if: {}", destination);
  // 预期输出: std::copy_if: [2, 4]

  source = {1, 2, 3, 4, 5};
  destination.clear();
  // 使用 std::ranges::copy_if
  std::ranges::copy_if(source, std::back_inserter(destination), isEven);
  fmt::println("std::ranges::copy_if: {}", destination);
  // 预期输出: std::ranges::copy_if: [2, 4]
}

// 示例 3: copy_n, ranges::copy_n
void example_copy_n() {
  std::vector source = {1, 2, 3, 4, 5};
  std::vector<int> destination(3);

  // 使用 std::copy_n
  std::copy_n(source.begin(), 3, destination.begin());
  fmt::println("std::copy_n: {}", destination);
  // 预期输出: std::copy_n: [1, 2, 3]

  source = {1, 2, 3, 4, 5};
  destination.resize(3);
  // 使用 std::ranges::copy_n
  std::ranges::copy_n(source.begin(), 3, destination.begin());
  fmt::println("std::ranges::copy_n: {}", destination);
  // 预期输出: std::ranges::copy_n: [1, 2, 3]
}

// 示例 4: copy_backward, ranges::copy_backward
void example_copy_backward() {
  std::vector source = {1, 2, 3, 4, 5};
  std::vector<int> destination(5);

  // 使用 std::copy_backward
  std::copy_backward(source.begin(), source.end(), destination.end());
  fmt::println("std::copy_backward: {}", destination);
  // 预期输出: std::copy_backward: [1, 2, 3, 4, 5]

  source = {1, 2, 3, 4, 5};
  destination.resize(5);
  // 使用 std::ranges::copy_backward
  std::ranges::copy_backward(source, destination.end());
  fmt::println("std::ranges::copy_backward: {}", destination);
  // 预期输出: std::ranges::copy_backward: [1, 2, 3, 4, 5]
}

// 示例 5: move, ranges::move
void example_move() {
  std::vector<int> source = {1, 2, 3, 4, 5};
  std::vector<int> destination(5);

  // 使用 std::move
  std::move(source.begin(), source.end(), destination.begin());
  fmt::println("std::move: {}", destination);
  // 预期输出: std::move: [1, 2, 3, 4, 5]

  source = {1, 2, 3, 4, 5};
  destination.resize(5);
  // 使用 std::ranges::move
  std::ranges::move(source, destination.begin());
  fmt::println("std::ranges::move: {}", destination);
  // 预期输出: std::ranges::move: [1, 2, 3, 4, 5]
}

// 示例 6: move_backward, ranges::move_backward
void example_move_backward() {
  std::vector<int> source = {1, 2, 3, 4, 5};
  std::vector<int> destination(5);

  // 使用 std::move_backward
  std::move_backward(source.begin(), source.end(), destination.end());
  fmt::println("std::move_backward: {}", destination);
  // 预期输出: std::move_backward: [1, 2, 3, 4, 5]

  source = {1, 2, 3, 4, 5};
  destination.resize(5);
  // 使用 std::ranges::move_backward
  std::ranges::move_backward(source, destination.end());
  fmt::println("std::ranges::move_backward: {}", destination);
  // 预期输出: std::ranges::move_backward: [1, 2, 3, 4, 5]
}

int main() {
    example_copy();
    example_copy_if();
    example_copy_n();
    example_copy_backward();
    example_move();
    example_move_backward();
    return 0;
}