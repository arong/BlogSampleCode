#include <iostream>
extern int extern_global;

int read_extern_global() { return extern_global; }

int x = read_extern_global() + 1;

int main() {
  std::cout << x << std::endl;
  return 0;
}
