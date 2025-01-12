#include <iostream>

// 普通函数
void display(int value) {
  std::cout << "Non-template function: " << value << std::endl;
}

// 模板函数
template <typename T>
void display(T value) {
  std::cout << "Template function: " << value << std::endl;
}

int main() {
  display(10);    // 调用普通函数(优先)
  display(10.5);  // 调用模板函数
  return 0;
}
