#include <iostream>

template <typename T>
constexpr T square(T x) {
  return x * x;
}

int main() {
  constexpr int result = square(5);  // 编译时计算
  std::cout << result << std::endl;  // 输出 25
  return 0;
}
