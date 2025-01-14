#include <iostream>
// overload D1
void fun(int, int, double) { std::cout << "D1" << std::endl; }

// overload D2
void fun(int, double, double) { std::cout << "D2" << std::endl; }

int main() {
  fun(4, 5, 6);  // 调用哪个?
}
