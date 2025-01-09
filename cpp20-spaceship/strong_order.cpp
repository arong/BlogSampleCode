#include <compare>
#include <iostream>

// 简单的包装类，使用默认的三向比较
struct MyInt {
  int value;
  auto operator<=>(const MyInt&) const = default;
};

// 带有多个成员的类，展示复合类型的比较
struct Point {
  int x, y;
  auto operator<=>(const Point&) const = default;
};

// 辅助函数：打印比较结果
void print_comparison(const auto& a, const auto& b) {
  auto cmp = a <=> b;
  if (cmp < 0) {
    std::cout << "less than\n";
  } else if (cmp > 0) {
    std::cout << "greater than\n";
  } else {
    std::cout << "equal to\n";
  }
}

int main() {
  // 示例1：基本整数比较
  MyInt a{5}, b{10};
  std::cout << "MyInt{5} vs MyInt{10}: ";
  print_comparison(a, b);

  // 示例2：相等值比较
  MyInt c{5}, d{5};
  std::cout << "MyInt{5} vs MyInt{5}: ";
  print_comparison(c, d);

  // 示例3：Point类比较
  Point p1{1, 2}, p2{1, 3};
  std::cout << "Point{1,2} vs Point{1,3}: ";
  print_comparison(p1, p2);

  // 示例4：直接使用<=>运算符
  std::cout << "Direct comparison result: ";
  if (p1 <=> p2 == std::strong_ordering::less) {
    std::cout << "p1 is less than p2\n";
  }

  return 0;
}
