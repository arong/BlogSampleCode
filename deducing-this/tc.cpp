#include <iostream>
#include <string>

class StringBuilder {
 public:
  std::string data;

  StringBuilder& append(std::string_view str) {
    data += str;
    return *this;
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
