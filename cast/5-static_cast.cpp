#include <cstdint>

struct MyStruct {};
void callback(void* handle) {
  auto p = static_cast<MyStruct*>(handle);
  //...
}

int main() {
  int i = 1;
  double d = static_cast<double>(i);

  int a = 1234;
  uint8_t u8 = static_cast<uint8_t>(a);

  struct Base {};
  struct Derived : public Base {};

  Derived derived;
  Base& rb = derived;
  Derived& rd = static_cast<Derived&>(rb);
  return 0;
}
