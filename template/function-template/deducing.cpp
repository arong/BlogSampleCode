template <typename T>
T add(T a, T b) {
  return a + b;
}

int main() {
  auto result = add(3, 5);              // 推定 T 为 int
  auto result2 = add(3.14, 2);          // 推定失败, 类型不一致
  auto result3 = add<double>(3.14, 2);  // OK
  return 0;
}
