#include <iostream>

void fun(const char* key) {
  if (key == "name") {
    std::cout << "get name\n";
  } else {
    std::cout << "something else\n";
  }
}
int main() {
  std::string name = "name";
  fun("name");        // output: get name
  fun(name.c_str());  // output: something else
  return 0;
}