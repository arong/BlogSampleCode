#include <iostream>
#include <stdexcept>

class Object {
 public:
  explicit Object(const std::string& name) : name_(name) {
    std::cout << "Constructing " << name_ << std::endl;
  }
  ~Object() { std::cout << "Destructing " << name_ << std::endl; }

 private:
  std::string name_;
};

void functionC() {
  Object c("C");
  throw std::runtime_error("Error in C");
}

void functionB() {
  Object b("B");
  functionC();
}

void functionA() {
  Object a("A");
  functionB();
}

int main() {
  functionA();
  return 0;
}
