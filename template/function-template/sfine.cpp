#include <iostream>
#include <type_traits>

// 通用模板: 处理非整型
template <typename T>
typename std::enable_if<!std::is_integral<T>::value>::type display(T value) {
  std::cout << "Non-integral type: " << value << std::endl;
}

// 特化模板: 处理整型
template <typename T>
typename std::enable_if<std::is_integral<T>::value>::type display(T value) {
  std::cout << "Integral type: " << value << std::endl;
}

int main() {
  display(10);    // 调用整型版本
  display(10.5);  // 调用非整型版本
  return 0;
}
