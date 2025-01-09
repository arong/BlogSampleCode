
struct Point {
  int x = 0;
  int y = 0;

  bool operator<(const Point& other) const {
    return (x < other.x) || (x == other.x && y < other.y);
  }
  bool operator<=(const Point& other) const { return !(other < *this); }
  bool operator>(const Point& other) const { return other < *this; }
  bool operator>=(const Point& other) const { return !(*this < other); }

  bool operator==(const Point& other) const {
    return x == other.x && y == other.y;
  }
  bool operator!=(const Point& other) const { return !(*this == other); }
};
