#include <iostream>
class Animal {
 public:
  virtual void voice() = 0;
};

class Dog : public Animal {
 public:
  void voice() override { std::cout << "wang wang\n"; }
};

int main() {
  int a = 1, b = 2;
  std::string sa = "1", sb = "2";

  int c = a + b;             // 3
  std::string sc = sa + sb;  // "12"

  std::cout << c << std::endl;
  std::cout << sc << std::endl;
}
