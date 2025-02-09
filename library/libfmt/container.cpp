#include <fmt/core.h>
#include <fmt/ranges.h>

#include <array>
#include <map>
#include <set>
#include <vector>

int main() {
  // 1. 打印容器
  // vector
  std::vector<int> vec = {1, 2, 3, 4, 5};
  fmt::println("Vector: {}", vec);  // 输出: Vector: [1, 2, 3, 4, 5]

  // array
  std::array<std::string, 3> arr = {"C++", "Python", "Rust"};
  fmt::println("Array: {}", arr);  // 输出: Array: [C++, Python, Rust]

  // map
  std::map<std::string, int> map = {
      {"Alice", 25}, {"Bob", 30}, {"Charlie", 20}};
  fmt::println("Map: {}", map);
  // 输出: Map: {"Alice": 25, "Bob": 30, "Charlie": 20}

  // set
  std::set<int> set = {3, 1, 4, 1, 5};
  fmt::println("Set: {}", set);  // 输出: Set: [1, 3, 4, 5]

  // 2. 嵌套容器
  std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  fmt::println("Matrix: {}", matrix);
  // 输出: Matrix: [[1, 2, 3], [4, 5, 6], [7, 8, 9]]

  // 3. 容器元素格式化
  std::vector<double> numbers = {3.14159, 2.71828, 1.41421};
  fmt::println("Numbers: {::.2f}", numbers);  // Numbers: [3.14, 2.72, 1.41]

  fmt::println("Vector: {::#x}", vec);  // Vector: [0x1, 0x2, 0x3, 0x4, 0x5]

  return 0;
}
