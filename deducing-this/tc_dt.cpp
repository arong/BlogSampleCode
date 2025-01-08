#include <iostream>
#include <string>

// 使用 deducing this: 链式调用更简洁
class StringBuilder {
 public:
  std::string data;

  auto&& append(this auto&& self, std::string_view str) {
    self.data += str;
    return std::forward<decltype(self)>(self);
  }
};

int main() {
  StringBuilder sb;
  sb.append("Hello").append(", ").append("world!");
  std::cout << sb.data << std::endl;  // 输出: Hello, world!
  std::cout << StringBuilder{}.append("Temporary").append(" Object").data
            << std::endl;  // 输出: Temporary Object
  return 0;
}
