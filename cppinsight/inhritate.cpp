#include <iostream>

class Base {
 public:
  virtual void call() { std::cout << "base called\n"; }
  virtual ~Base() = default;
};

class Derived : public Base {
 public:
  void call() override { std::cout << "derived called\n"; }
};

int main() {
  Base* p = nullptr;
  Derived d;
  p = &d;

  p->call();
}
