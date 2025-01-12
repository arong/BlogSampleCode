#include <iostream>
#include <type_traits>

struct Base {
  virtual void f() { std::cout << "base\n"; }
  virtual ~Base() = default;
};
struct Derived : public Base {
  void f() override { std::cout << "Derived\n"; }
};

struct Other : public Base {
  void f() override { std::cout << "Other\n"; }
};

int main() {
  Derived d;
  Base& b = d;  // OK

  d.f();  // Derived
  b.f();  // Derived

  Other& a = static_cast<Other&>(b);  // 危险, 转换到了其他类型
  a.f();                              // Derived
  static_assert(std::is_same<decltype(a), Other&>::value, "not the same");
  return 0;
}
