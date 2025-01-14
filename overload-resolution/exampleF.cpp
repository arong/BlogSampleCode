#include <iostream>
// overload F1
void fun(int &) { std::cout << "F1" << std::endl; }

// overload F2
void fun(int) { std::cout << "F2" << std::endl; }

int main() {
  fun(42);  // 调用哪个?
}
