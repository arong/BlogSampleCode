#include <iostream>

// 函数模板的定义
template <typename T>
T Max(T a, T b) {
  return (a > b) ? a : b;
}

int main() {
  std::cout << Max(10, 20) << std::endl;      // 模板实例化: int
  std::cout << Max(3.14, 2.71) << std::endl;  // 模板实例化: double
  std::cout << Max('A', 'Z') << std::endl;    // 模板实例化: char
  return 0;
}
