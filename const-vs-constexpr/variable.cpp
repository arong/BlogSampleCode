#include <string>

const int a = 42;  // 可以绑定常量
void fun(std::string& s) {
  // 可以绑定动态值, 只表明size为只读属性
  const auto size = s.size();
  for (int i = 0; i < size; i++) {
    // ...
  }
}

constexpr int square(int x) { return x * x; }
constexpr int b = 42;         // OK, 常量
constexpr int c = square(b);  // OK, 常量函数返回值

int main() { return 0; }
