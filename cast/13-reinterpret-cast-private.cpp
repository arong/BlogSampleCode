#include <iostream>

struct B {
  void m() { std::cout << "private to D\n"; }
};

struct D : private B {};

int main() {
  D d;
  B& b = reinterpret_cast<B&>(d);
  b.m();
  return 0;
}
