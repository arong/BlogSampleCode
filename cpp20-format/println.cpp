#include <print>

int main() {
  std::println(
      "This is a println example!");  // 输出：This is a println example!
  std::println("Value: {}, Pi: {:.2f}", 10,
               3.14159);  // 输出：Value: 10, Pi: 3.14
  return 0;
}
