#include <cstdio>

struct A {
  explicit A(int) { puts("A"); }
};

struct E {
  operator int() {
    puts("B::operator int");
    return 0;
  }
};

int main() {
  E e;
  A a = static_cast<A>(e);
  return 0;
}
