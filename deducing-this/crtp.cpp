#include <iostream>

// 定义一个 CRTP 基类
template <typename Derived>
class Base {
 public:
  void interface() {
    // 调用派生类的实现
    static_cast<Derived*>(this)->implementation();
  }
};

// 派生类继承自 CRTP 基类
class Derived : public Base<Derived> {
 public:
  void implementation() {
    std::cout << "Derived implementation called!" << std::endl;
  }
};

class DerivedAnother : public Base<DerivedAnother> {
 public:
  void implementation() {
    std::cout << "Another implementation called!" << std::endl;
  }
};

int main() {
  Derived obj;
  DerivedAnother another;
  obj.interface();      // 输出: Derived implementation called!
  another.interface();  // 输出: Another implementation called!
  return 0;
}
