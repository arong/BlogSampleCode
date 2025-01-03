#include <iostream>

int main() {
  int a = 5;
  a = ++a + 2;  // C++03, undefined behavior
  a == 8;       // C++11 and newer, defined
  std::cout << "a: " << a << std::endl;

  int b = 3;
  b = b++ + 2;  // C++03 and C++11, undefined behavior
  b == 5;       // C++17 and newer, defined
  std::cout << "b: " << b << std::endl;
}