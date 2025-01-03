#include <iostream>
#include <string>
#include <type_traits>
#include <typeinfo>
#include <variant>

int main() {
  std::variant<int, double, std::string> value = 42;
  value = 3.14;
  value = "Hello, Variant!";

  // 访问具体类型
  std::visit(
      [](auto&& arg) {
        std::cout << arg << std::endl;

        // 获取arg的对应类型
        using UnderlyingType =
            std::remove_pointer_t<std::decay_t<decltype(arg)>>;
        // 检查不同类型
        if constexpr (std::is_same_v<UnderlyingType, std::string>) {
          std::cout << "std::string type found\n";
        } else if constexpr (std::is_integral_v<UnderlyingType>) {
          std::cout << "integer type found\n";
        } else if constexpr (std::is_floating_point_v<UnderlyingType>) {
          std::cout << "float point type found\n";
        } else {
          std::cout << "unknown type: " << typeid(arg).name() << '\n';
        }
      },
      value);

  return 0;
}
