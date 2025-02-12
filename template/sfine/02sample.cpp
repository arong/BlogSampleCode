#include <iostream>
#include <type_traits>

// 通用版本
template <typename T>
void print(T value) {
  std::cout << "Generic print: " << value << std::endl;
}

// 针对指针类型的特化
template <typename T>
typename std::enable_if<std::is_pointer<T>::value, void>::type print(T* value) {
  std::cout << "Pointer print: " << *value << std::endl;
}

int main() {
  int x = 10;
  print(x);   // 调用通用版本
  print(&x);  // 调用指针特化版本
  return 0;
}
