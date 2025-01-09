int main() {
  int x = 0;

  int& ref = x;
  ref = 1;  // OK

  const int& cref = x;
  cref = 1;  // Error, 不可以通过常量引用改变绑定变量值
  return 0;
}
