#include <iostream>

void use_pointer(int* p) { std::cout << "*p = " << *p << std::endl; }
void modify_pointer(int* p) {
  *p = 42;
  std::cout << "\tmodify_pointer *p <- 42\n"
            << "\tmodify_pointer *p = " << *p << std::endl;
}

int main() {
  const int i = 7;
  use_pointer(const_cast<int*>(&i));
  modify_pointer(const_cast<int*>(&i));

  std::cout << "i = " << i << std::endl;  // i = 7
  int j = 4;
  const int* cj = &j;
  modify_pointer(const_cast<int*>(cj));
  std::cout << "i = " << i << std::endl;  // i = 7

  return 0;
}
