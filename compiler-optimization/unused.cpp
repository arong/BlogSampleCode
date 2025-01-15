#include <iostream>

void unusedFunction() {
  // 此函数未被其他任何函数调用
  std::cout << "This function is never called.\n";
}

int main() {
  int unusedVariable = 42;  // 定义了但未使用
  return 0;
}
