#include <format>
#include <print>
#include <string>

struct Point {
  int x, y;
};

template <>
struct std::formatter<Point> {
  constexpr auto parse(std::format_parse_context& ctx) { return ctx.begin(); }
  auto format(const Point& p, std::format_context& ctx) const {
    return std::format_to(ctx.out(), "({}, {})", p.x, p.y);
  }
};

int main() {
  Point p{3, 4};
  std::println("Point: {}", p);  // Output: Point: (3, 4)
  return 0;
}
