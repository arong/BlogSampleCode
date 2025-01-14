#include <iostream>
// overload E1
void fun(int &) { std::cout << "E1" << std::endl; }

// overload E2
void fun(int) { std::cout << "E2" << std::endl; }

int main() {
  int x = 42;
  fun(x);  // 调用哪个?
}
