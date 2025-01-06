#include <iostream>

void recursive() {
  int arr[1000];
  recursive();  // 导致栈溢出
}

int main() {
  recursive();
  return 0;
}
