#include <iostream>

template <typename T>
T cubic(T len) {
  return len * len * len;
}

int main() {
  std::cout << "cubic signed: " << cubic(3000) << std::endl;     // UB
  std::cout << "cubic unsigned: " << cubic(3000u) << std::endl;  // OK
  return 0;
}