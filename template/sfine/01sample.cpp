#include <iostream>
#include <type_traits>

// 针对整数类型的重载
template <typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type process(
    T value) {
  std::cout << "Processing integral type: " << value << std::endl;
}

// 针对浮点类型的重载
template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, void>::type process(
    T value) {
  std::cout << "Processing floating-point type: " << value << std::endl;
}

int main() {
  process(42);    // 调用整数版本
  process(3.14);  // 调用浮点数版本
  return 0;
}
