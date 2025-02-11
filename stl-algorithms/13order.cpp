#include <fmt/ranges.h>

#include <algorithm>
#include <random>
#include <ranges>
#include <vector>

// reverse
void reverseExample() {
  std::vector vec = {1, 2, 3, 4, 5};
  fmt::println("Original vector for reverse: {}", vec);
  // 预期输出: Original vector for reverse: [1, 2, 3, 4, 5]
  std::reverse(vec.begin(), vec.end());
  fmt::println("After std::reverse: {}", vec);
  // 预期输出: After std::reverse: [5, 4, 3, 2, 1]
}

// ranges::reverse
void rangesReverseExample() {
  std::vector vec = {1, 2, 3, 4, 5};
  fmt::println("Original vector for ranges::reverse: {}", vec);
  // 预期输出: Original vector for ranges::reverse: [1, 2, 3, 4, 5]
  std::ranges::reverse(vec);
  fmt::println("After std::ranges::reverse: {}", vec);
  // 预期输出: After std::ranges::reverse: [5, 4, 3, 2, 1]
}

// reverse_copy
void reverseCopyExample() {
  std::vector vec = {1, 2, 3, 4, 5};
  std::vector<int> result(vec.size());
  fmt::println("Original vector for reverse_copy: {}", vec);
  // 预期输出: Original vector for reverse_copy: [1, 2, 3, 4, 5]
  std::reverse_copy(vec.begin(), vec.end(), result.begin());
  fmt::println("After std::reverse_copy: {}", result);
  // 预期输出: After std::reverse_copy: [5, 4, 3, 2, 1]
}

// ranges::reverse_copy
void rangesReverseCopyExample() {
  std::vector vec = {1, 2, 3, 4, 5};
  std::vector<int> result(vec.size());
  fmt::println("Original vector for ranges::reverse_copy: {}", vec);
  // 预期输出: Original vector for ranges::reverse_copy: [1, 2, 3, 4, 5]
  std::ranges::reverse_copy(vec, result.begin());
  fmt::println("After std::ranges::reverse_copy: {}", result);
  // 预期输出: After std::ranges::reverse_copy: [5, 4, 3, 2, 1]
}

// rotate
void rotateExample() {
  std::vector vec = {1, 2, 3, 4, 5};
  fmt::println("Original vector for rotate: {}", vec);
  // 预期输出: Original vector for rotate: [1, 2, 3, 4, 5]
  std::rotate(vec.begin(), vec.begin() + 2, vec.end());
  fmt::println("After std::rotate (rotate by 2): {}", vec);
  // 预期输出: After std::rotate (rotate by 2): [3, 4, 5, 1, 2]
}

// ranges::rotate
void rangesRotateExample() {
  std::vector vec = {1, 2, 3, 4, 5};
  fmt::println("Original vector for ranges::rotate: {}", vec);
  // 预期输出: Original vector for ranges::rotate: [1, 2, 3, 4, 5]
  std::ranges::rotate(vec, vec.begin() + 2);
  fmt::println("After std::ranges::rotate (rotate by 2): {}", vec);
  // 预期输出: After std::ranges::rotate (rotate by 2): [3, 4, 5, 1, 2]
}

// rotate_copy
void rotateCopyExample() {
  std::vector vec = {1, 2, 3, 4, 5};
  std::vector<int> result(vec.size());
  fmt::println("Original vector for rotate_copy: {}", vec);
  // 预期输出: Original vector for rotate_copy: [1, 2, 3, 4, 5]
  std::rotate_copy(vec.begin(), vec.begin() + 2, vec.end(), result.begin());
  fmt::println("After std::rotate_copy (rotate by 2): {}", result);
  // 预期输出: After std::rotate_copy (rotate by 2): [3, 4, 5, 1, 2]
}

// ranges::rotate_copy
void rangesRotateCopyExample() {
  std::vector<int> vec = {1, 2, 3, 4, 5};
  std::vector<int> result(vec.size());
  fmt::println("Original vector for ranges::rotate_copy: {}", vec);
  // 预期输出: Original vector for ranges::rotate_copy: [1, 2, 3, 4, 5]
  std::ranges::rotate_copy(vec, vec.begin() + 2, result.begin());
  fmt::println("After std::ranges::rotate_copy (rotate by 2): {}", result);
  // 预期输出: After std::ranges::rotate_copy (rotate by 2): [3, 4, 5, 1, 2]
}

// shift_left
void shiftLeftExample() {
  std::vector<int> vec = {1, 2, 3, 4, 5};
  fmt::println("Original vector for shift_left: {}", vec);
  // 预期输出: Original vector for shift_left: [1, 2, 3, 4, 5]
  auto new_end = std::shift_left(vec.begin(), vec.end(), 2);
  vec.erase(new_end, vec.end());
  vec.resize(5);
  fmt::println("After std::shift_left (shift by 2): {}", vec);
  // 预期输出: After std::shift_left (shift by 2): [3, 4, 5, 0, 0]
}

// ranges::shift_left
void rangesShiftLeftExample() {
#ifdef _MSC_VER
  std::vector<int> vec = {1, 2, 3, 4, 5};
  fmt::println("Original vector for ranges::shift_left: {}", vec);
  // 预期输出: Original vector for ranges::shift_left: [1, 2, 3, 4, 5]
  auto r_new_end = std::ranges::shift_left(vec, 2);
  vec.erase(r_new_end.begin(), r_new_end.end());
  vec.resize(5);
  fmt::println("After std::ranges::shift_left (shift by 2): {}", vec);
  // 预期输出: After std::ranges::shift_left (shift by 2): [3, 4, 5, 0, 0]
#endif
}

// shift_right
void shiftRightExample() {
  std::vector<int> vec = {1, 2, 3, 4, 5};
  fmt::println("Original vector for shift_right: {}", vec);
  // 预期输出: Original vector for shift_right: [1, 2, 3, 4, 5]
  auto new_end = std::shift_right(vec.begin(), vec.end(), 2);
  vec.erase(new_end, vec.end());
  vec.resize(5);
  fmt::println("After std::shift_right (shift by 2): {}", vec);
  // 预期输出: After std::shift_right (shift by 2): [0, 0, 1, 2, 3]
}

// ranges::shift_right

void rangesShiftRightExample() {
#ifdef _MSC_VER
  std::vector<int> vec = {1, 2, 3, 4, 5};
  fmt::println("Original vector for ranges::shift_right: {}", vec);
  // 预期输出: Original vector for ranges::shift_right: [1, 2, 3, 4, 5]
  auto r_new_end = std::ranges::shift_right(vec, 2);
  vec.erase(r_new_end.begin(), r_new_end.end());
  vec.resize(5);
  fmt::println("After std::ranges::shift_right (shift by 2): {}", vec);
  // 预期输出: After std::ranges::shift_right (shift by 2): [0, 0, 1, 2, 3]
#endif
}

// shuffle
void shuffleExample() {
  std::vector<int> vec = {1, 2, 3, 4, 5};
  std::random_device rd;
  std::mt19937 g(rd());
  fmt::println("Original vector for shuffle: {}", vec);
  // 预期输出: Original vector for shuffle: [1, 2, 3, 4, 5]
  std::shuffle(vec.begin(), vec.end(), g);
  fmt::println("After std::shuffle: {}", vec);  // 预期输出: 随机打乱后的向量
}

// ranges::shuffle
void rangesShuffleExample() {
  std::vector<int> vec = {1, 2, 3, 4, 5};
  std::random_device rd;
  std::mt19937 g(rd());
  fmt::println("Original vector for ranges::shuffle: {}", vec);
  // 预期输出: Original vector for ranges::shuffle: [1, 2, 3, 4, 5]
  std::ranges::shuffle(vec, g);
  fmt::println("After std::ranges::shuffle: {}",
               vec);  // 预期输出: 随机打乱后的向量
}

int main() {
  reverseExample();
  rangesReverseExample();
  reverseCopyExample();
  rangesReverseCopyExample();
  rotateExample();
  rangesRotateExample();
  rotateCopyExample();
  rangesRotateCopyExample();
  shiftLeftExample();
  rangesShiftLeftExample();
  shiftRightExample();
  rangesShiftRightExample();
  shuffleExample();
  rangesShuffleExample();
  return 0;
}
