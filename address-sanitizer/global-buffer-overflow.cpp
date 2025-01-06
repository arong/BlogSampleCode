#include <iostream>

char global_arr[10];

int main() {
  global_arr[10] = 'A';  // 越界访问全局缓冲区
  return 0;
}
