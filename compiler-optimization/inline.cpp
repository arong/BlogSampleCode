#include <iostream>
inline int add(int x, int y) { return x + y; }

void inliningExample() {
  int result = add(10, 20);
  std::cout << result << std::endl;
}

int main() {
  inliningExample();
  return 0;
}
