#include <iostream>

template <typename T, typename = std::enable_if_t<std::is_integral<T>::value>>
void func(T t) {
  std::cout << "Integral type: " << t << std::endl;
}

int main() {
  func(10);
  // func("hello"); // 编译错误
  return 0;
}
