#include <cstdint>

struct A {};
struct B {
  int i;
  int j;
};

int main() {
  int i = 0;
  int* pi = &i;
  uintptr_t uipt = reinterpret_cast<uintptr_t>(pi);
  float& f = reinterpret_cast<float&>(i);
  A a;
  B* pb = reinterpret_cast<B*>(&a);
  char buff[10];
  B* b_buff = reinterpret_cast<B*>(buff);
  return 0;
}
