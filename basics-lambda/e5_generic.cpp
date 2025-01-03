#include <iostream>
#include <string>

int main() {
  auto add = [](auto x, auto y) { return x + y; };
  std::cout << add(1, 2) << '\n';      // 输出 3
  std::cout << add(1.5, 2.5) << '\n';  // 输出 4.0
  std::cout << add(std::string("Hello "), "world.")
            << '\n';  // 输出 Hello world.
  return 0;
}
