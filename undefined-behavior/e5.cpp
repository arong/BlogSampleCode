#include <iostream>

bool baz() { return true; }
bool foo(int a, int b) { a == b; }
bool bar() { return false; }

int main() {
  int a = 1;
  int b = 2;
  std::cout << "a == b: " << foo(a, b) << std::endl;
  std::cout << bar() << baz() << std::endl;
  return 0;
}