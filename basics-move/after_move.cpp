#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> vec;
  std::string s = "Hello";

  vec.emplace_back(std::move(s));  // move
  std::cout << s << std::endl;     // s依旧可用, 但不确定其值
  s = "world";                     // OK, 可以被重新赋值
  std::cout << s << std::endl;     // OK, s目前有明确的值
  return 0;
}
