// 重载函数 1
void fun(int) {}

// 重载函数 2
void fun(int, double) {}

int main() {
  fun(42);        // 调用函数 1
  fun(42, 3.14);  // 调用函数 2
}
