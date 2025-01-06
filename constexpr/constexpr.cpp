int main() {
  // 初始化常量表达式
  constexpr int min_size = 10;             // OK, 字面量初始化
  constexpr int max_size = min_size + 10;  // OK, 常量表达式
  // min_size = 20;                        // Error, 常量不能被修改

  return 0;
}
