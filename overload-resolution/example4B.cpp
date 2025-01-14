#include <iostream>

// overload B1
void fun(char value) { std::cout << "B1" << std::endl; }

// overload B2
template <typename T>
void fun(T value) {
  std::cout << "B2" << std::endl;
}

int main() {
  fun(42);  // 调用哪个?
}
