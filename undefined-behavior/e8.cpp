#include <iostream>
#include <string>

const std::string global = "Hello";

void fun(const std::string &input) {
  std::string &v = const_cast<std::string &>(input);
  v = "fun";
}

int main() {
  const std::string local = "World";
  fun(local);
  std::cout << local << std::endl;

  fun(global);
  std::cout << global << std::endl;
  return 0;
}