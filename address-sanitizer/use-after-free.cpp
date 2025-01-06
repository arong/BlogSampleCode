#include <iostream>

int main() {
  int* ptr = new int(10);
  delete ptr;
  *ptr = 20;  // 使用已释放的内存
  return 0;
}
