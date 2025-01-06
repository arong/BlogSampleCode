constexpr int square(int x) { return x * x; }

int main() {
  constexpr int a = 3;
  constexpr int b = 4;
  constexpr int c = square(a) + square(b);  // OK, a 和 b 是常量
  int d = square(5);                        // OK, d 不要求是常量

  int e = 3;
  constexpr int f =
      square(e);  // 错误, e是普通变量, 不能作为constexpr函数的参数. 非
                  // constexpr 参数会导致编译错误

  auto abs = [](int x) constexpr -> int { return x < 0 ? -x : x; };
  constexpr int g = abs(-1);  // OK

  return abs(0);
}
