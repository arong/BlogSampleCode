#include <iostream>
// overload H1
void fun(int &) { std::cout << "H1" << std::endl; }

// overload H2
void fun(int &&) { std::cout << "H2" << std::endl; }

int main() {
  fun(42);  // 调用哪个?
}
