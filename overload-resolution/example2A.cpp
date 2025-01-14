#include <iostream>
// overload A1
void fun(char value) { std::cout << "A1" << std::endl; }

// overload A2
void fun(long value) { std::cout << "A2" << std::endl; }

int main() {
  fun(42);  // 调用哪个?
}
