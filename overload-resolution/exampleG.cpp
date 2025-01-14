#include <iostream>
// overload G1
void fun(int &) { std::cout << "G1" << std::endl; }

// overload G2
void fun(int &&) { std::cout << "G2" << std::endl; }

int main() {
  int x = 42;
  fun(x);  // 调用哪个?
}
