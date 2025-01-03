#include <any>
#include <iostream>
#include <string>

int main() {
  std::any value = 42;
  value = 4.0;                         // OK
  value = std::string("Hello, Any!");  // OK

  value = 42;
  if (value.type() == typeid(int)) {
    int number = std::any_cast<int>(value);
    std::cout << number << std::endl;
  }

  value = 42;
  try {
    std::string str = std::any_cast<std::string>(value);  // 错误, 抛出异常
  } catch (const std::bad_any_cast& e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
