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
  auto result = divide(10, 0).transform_error(
      [](const std::string& err) { return "[Transformed Error] " + err; });

  if (!result) {
    std::cout << result.error() << std::endl;
    // 输出: [Transformed Error] Division by zero
  }
  return 0;
}
