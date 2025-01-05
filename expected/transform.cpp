#include <expected>
#include <iostream>
#include <string>

std::expected<int, std::string> divide(int a, int b) {
  if (b == 0) {
    return std::unexpected("Division by zero");
  }
  return a / b;
}

void with_transform(int a, int b) {
  auto result = divide(a, b).transform([](int value) {
    return value * 2;  // 成功值 * 2
  });

  if (result) {
    std::cout << "Success: " << *result << '\n';
  } else {
    std::cout << "Error: " << result.error() << '\n';
  }
}

void transform_type(int a, int b) {
  // 结果为 expected<size_t, std::string>
  auto process = divide(a, b)
                     .transform([](int value) {
                       return std::to_string(value + 10);  // int -> string
                     })
                     .transform([](const std::string& str) {
                       return str.size();  // string -> size_t
                     });
  if (process) {
    std::cout << "Success, process= " << *process << '\n';
  } else {
    std::cout << "Error: process=" << process.error() << '\n';
  }
}

int main() {
  with_transform(10, 2);  // 输出: Success: 10
  with_transform(10, 0);  // 输出: Error: Division by zero

  transform_type(10, 2);  //
  transform_type(10, 0);  //
  return 0;
}
