#include <iostream>

// overload C1
void fun(double, int, int) { std::cout << "C1" << std::endl; }

// overload C2
void fun(int, double, double) { std::cout << "C2" << std::endl; }

int main() {
  fun(4, 5, 6);  // 调用哪个?
}
