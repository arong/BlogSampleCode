int main() {
  constexpr int* np = nullptr;  // OK

  static int sa = 0;         // 静态变量
  constexpr int* psa = &sa;  // OK

  static const int ca = 0;         // 静态常量
  constexpr const int* pca = &ca;  // OK

  static constexpr int sb = 0;     // 静态constexpr
  constexpr const int* psb = &sb;  // OK

  constexpr int x = 42;
  constexpr const int* p2 = &x;  // Error

  const int cy = 1;
  constexpr const int* p3 = &cy;  // Error

  return 0;
}
