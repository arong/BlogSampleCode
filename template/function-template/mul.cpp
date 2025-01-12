template <typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
  return a + b;
}

#include <iostream>
int main() {
  std::cout << add(3, 5.5) << std::endl;  // 推导为 double add(int, double)
  std::cout << add(2.5, 4) << std::endl;  // 推导为 double add(double, int)
  return 0;
}
