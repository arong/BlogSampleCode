#include <compare>
#include <iostream>

struct Point {
  int x = 0;
  int y = 0;

  auto operator<=>(const Point&) const = default;  // 自动生成所有比较操作符
};

int main() {
  Point p1{1, 2}, p2{2, 3};

  if (p1 < p2) {
    std::cout << "p1 is less than p2\n";
  }

  auto result = (p1 <=> p2);
  if (result < 0) {
    std::cout << "p1 is less than p2\n";
  } else if (result == 0) {
    std::cout << "p1 is equal to p2\n";
  } else {
    std::cout << "p1 is greater than p2\n";
  }
}
