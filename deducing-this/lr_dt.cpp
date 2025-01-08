
// 使用 deducing this: 统一左值和右值版本
class Counter {
 public:
  int value = 0;

  void increment(this auto&& self) { ++self.value; }
};

int main() {
  Counter mc;
  mc.increment();         // 调用左值版本
  Counter{}.increment();  // 调用右值版本
  return 0;
}
