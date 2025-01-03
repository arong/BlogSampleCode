#include <iostream>

template <typename T1, typename T2>
void fun(T1 &x, T2 &y) {
  x << y;
}

int main() {
  int a = 1;
  int b = 1000;
  fun(a, b);              // UB: 左移操作的移动位数超过了类型的宽度
  fun(std::cout, "cat");  // OK
}