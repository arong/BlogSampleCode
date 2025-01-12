#include <cstdio>
#include <vector>

struct A {
  virtual ~A() = default;
};
struct B : public A {};
struct C : public A {};
int main() {
  C c;
  B b;
  std::vector<A*> a_list = {&c, &b};
  for (size_t i = 0; i < a_list.size(); ++i) {
    A* pa = a_list[i];
    if (dynamic_cast<B*>(pa)) {
      printf("a_list[%lu] was a B\r\n", i);
    }
    if (dynamic_cast<C*>(pa)) {
      printf("a_list[%lu] was a C\r\n", i);
    }
  }
  return 0;
}
