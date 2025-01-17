#include <exception>
#include <iostream>
#include <stdexcept>

void funcB() { throw std::runtime_error("Error in B"); }

void funcA() { funcB(); }

int main() {
  try {
    funcA();
  } catch (const std::exception& ex) {
    std::cerr << "Caught: " << ex.what() << std::endl;
  }
}
