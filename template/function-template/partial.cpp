#include <iostream>

// 通用模板
template <typename T>
void display(T value) {
  std::cout << "General template: " << value << std::endl;
}

// 模板特化
template <>
void display<int>(int value) {
  std::cout << "Specialized template for int: " << value << std::endl;
}

int main() {
  display(10);    // 调用特化版本
  display(10.5);  // 调用通用模板
  return 0;
}
