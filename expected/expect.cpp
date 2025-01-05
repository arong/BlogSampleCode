#include <expected>
#include <iostream>
#include <string>

std::expected<int, std::string> divide(int a, int b) {
  if (b == 0) {
    return std::unexpected("Division by zero");
  }
  return a / b;
}

int main() {
  if (auto result = divide(10, 2); result) {
    std::cout << "Result: " << *result << '\n';
  } else {
    std::cout << "Error: " << result.error() << '\n';
  }

  if (auto result = divide(10, 0); result) {
    std::cout << "Result: " << *result << '\n';
  } else {
    std::cout << "Error: " << result.error() << '\n';
  }
  return 0;
}
