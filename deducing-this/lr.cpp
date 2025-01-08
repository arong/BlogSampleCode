// 传统方式: 需要为左值和右值分别实现两个函数
class Counter {
 public:
  int value = 0;

  void increment() & {  // 左值版本
    ++value;
  }

  void increment() && {  // 右值版本
    ++value;
  }
};

int main() {
  Counter tc;
  tc.increment();         // 调用左值版本
  Counter{}.increment();  // 调用右值版本
  return 0;
}
