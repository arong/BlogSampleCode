#include <iostream>

int main() {
#ifdef DEBUG
  std::cout << "Running in Debug mode" << std::endl;
#else
  std::cout << "Running in Release mode" << std::endl;
#endif
  return 0;
}
