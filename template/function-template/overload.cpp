#include <iostream>

// 模板定义 1: 单个参数
template <typename T>
void display(T value) {
  std::cout << "Single parameter: " << value << std::endl;
}

// 模板定义 2: 两个参数
template <typename T, typename U>
void display(T value1, U value2) {
  std::cout << "Two parameters: " << value1 << " and " << value2 << std::endl;
}

int main() {
  display(10);        // 调用第一个模板
  display(10, 20.5);  // 调用第二个模板
  return 0;
}
