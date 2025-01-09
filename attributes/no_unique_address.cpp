#include <iostream>

struct Empty {
  // Empty class with no data members
};

struct Optimized {
  [[no_unique_address]] Empty e;  // May share memory with other members
  int value;

  void display() const { std::cout << "Value: " << value << '\n'; }
};

int main() {
  Optimized obj;
  obj.value = 42;
  obj.display();

  std::cout << "Size of Optimized: " << sizeof(Optimized) << '\n';
  return 0;
}
