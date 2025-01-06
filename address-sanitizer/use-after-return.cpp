#include <iostream>

int* dangling_pointer() {
  int local_var = 42;
  return &local_var;  // 返回局部变量的地址
}

int main() {
  int* ptr = dangling_pointer();
  std::cout << *ptr << std::endl;  // 使用悬空指针
  return 0;
}
