#include <iostream>

int main() {
  int* p = nullptr;  // line 1
  *p = 42;           // line 2
  int b;             // line 3
  p = &b;            // line 4
  std::cout << *p;   // line 5
  std::cout << b;    // line 6
}