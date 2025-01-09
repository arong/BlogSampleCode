#include <compare>
#include <iostream>

class Point {
 private:
  int x;
  int y;

 public:
  Point(int x_coord, int y_coord) : x(x_coord), y(y_coord) {}

  // C++20 spaceship operator for strong equality
  auto operator<=>(const Point& other) const = default;

  // For demonstration purposes, let's add a method to print the point
  void print() const { std::cout << "Point(" << x << ", " << y << ")\n"; }
};

int main() {
  Point p1(1, 2);
  Point p2(1, 2);
  Point p3(3, 4);

  // Test equality
  std::cout << "p1 == p2: " << (p1 == p2) << "\n";  // true
  std::cout << "p1 == p3: " << (p1 == p3) << "\n";  // false

  // Test ordering
  std::cout << "p1 < p3: " << (p1 < p3) << "\n";  // true
  std::cout << "p3 > p1: " << (p3 > p1) << "\n";  // true

  std::cout << "\nPoints:\n";
  p1.print();
  p2.print();
  p3.print();

  return 0;
}
