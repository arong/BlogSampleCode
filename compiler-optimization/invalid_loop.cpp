#include <iostream>
int main() {
  for (int i = 0; i < 0; i++) {
    // 死代码，循环条件初始就不成立
    std::cout << "This loop will never execute.\n";
  }
}
