#include <iostream>

template <typename T>
T Max(T a, T b) {
  return (a > b) ? a : b;
}

template <typename T>
T add(T a, T b) {
  return a + b;
}

// multi
template <typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
  return a + b;
}

// default
template <typename T = int, typename U = double>
class Pair {
 public:
  T first;
  U second;
  Pair(T a, U b) : first(a), second(b) {}
};

// overload
template <typename T>
void display(T value) {
  std::cout << "Single parameter: " << value << std::endl;
}

// 模板定义 2: 两个参数
template <typename T, typename U>
void display(T value1, U value2) {
  std::cout << "Two parameters: " << value1 << " and " << value2 << std::endl;
}

int main() {
  std::cout << Max(10, 20) << std::endl;      // 模板实例化: int
  std::cout << Max(3.14, 2.71) << std::endl;  // 模板实例化: double
  std::cout << Max('A', 'Z') << std::endl;    // 模板实例化: char

  std::cout << Max<double>(3, 5) << std::endl;  // 输出 5.0

  // deducing
  auto result = add(3, 5);      // 推定 T 为 int
  auto result2 = add(3.14, 2);  // 推定失败, 类型不一致

  auto result3 = add<double>(3.14, 2);  // OK

  // default
  Pair<> p1(1, 2.5);        // 使用默认参数 T=int, U=double
  Pair<int, int> p2(3, 4);  // 显式指定参数
  std::cout << p1.first << ", " << p1.second << std::endl;  // 输出 1, 2.5
  std::cout << p2.first << ", " << p2.second << std::endl;  // 输出 3, 4
  return 0;
}
