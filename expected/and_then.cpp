#include <expected>
#include <iostream>
#include <string>

std::expected<int, std::string> divide(int a, int b) {
  if (b == 0) {
    return std::unexpected("Division by zero");
  }
  return a / b;
}

std::expected<std::string, std::string> evenOdd(int x) {
  if (x & 1 == 0) {
    return "odd";
  } else {
    return "even";
  }
}

int main() {
  // 对成功值进行连续计算
  auto result = divide(10, 2).and_then([](int value) {
    return evenOdd(value);  // 调用另一个返回 expected的函数
  });
  if (result) {
    std::cout << "Success: " << *result << '\n';
  } else {
    std::cout << "Error: " << result.error() << '\n';
  }

  // 可以连续计算多次
  auto finalResult =
      divide(10, 2)
          .and_then([](int value) {
            return divide(value, 2);  // 再次除法
          })
          .and_then([](int newValue) -> std::expected<int, std::string> {
            if (newValue == 2) {
              return std::unexpected("We don't like the value 2!");
            }
            return newValue * 10;
          });
  if (finalResult) {
    std::cout << "Final Success: " << *finalResult << '\n';
  } else {
    std::cout << "Final Error: " << finalResult.error() << '\n';
  }
  return 0;
}
