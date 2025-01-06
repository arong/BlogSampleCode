// constexpr 修饰的类实例
struct Point {
  constexpr Point(int x, int y) : x_(x), y_(y) {}
  constexpr int x() const { return x_; }
  constexpr int y() const { return y_; }

 private:
  int x_;
  int y_;
};

struct OldPoint {
  OldPoint(int x) : x_(x) {}

 private:
  int x_;
};

int main() {
  constexpr Point origin{0, 0};  // OK
  constexpr Point dst{1, 1};     // OK

  //   constexpr OldPoint old_origin{0};  // Error,
  //   OldPoint的构造函数不是constexpr的
  return 0;
}
