#include <string>

void func(int x = 10) {}

void bar(std::string s = "my default string") {}

int main() {
  func();  // 使用默认参数
  bar();   // 使用默认参数
  bar();   // 使用默认参数
  return 0;
}
