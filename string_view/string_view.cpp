#include <iostream>
#include <string_view>

constexpr std::string_view compile_time_string() {
  return "Compile-time string";
}

int main() {
  constexpr std::string_view sv = compile_time_string();
  std::cout << sv << std::endl;  // 输出: Compile-time string
  return 0;
}
