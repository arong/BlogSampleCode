int main() {
  static int sa = 1;
  constexpr const int& rsa = sa;  // rsa 是绑定到 sa 的引用
  sa = 1;                         // OK
  rsa = 1;                        // Error

  static constexpr int sca = 42;   // 静态constexpr
  constexpr const int& ref = sca;  // ref 是绑定到 sca 的引用
  sca = 1;                         // Error
  ref = 1;                         // Error

  return 0;
}
