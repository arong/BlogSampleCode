#include <iostream>

struct B1 {
  virtual ~B1() = default;
  int i;
};

struct B2 {
  virtual ~B2() = default;
  int j;
};

struct Derived : public B1, public B2 {
  int k;
};

void Compare(void* p1, void* p2) {
  if (p1 == p2) {
    std::cout << "Same.\n";
  } else {
    std::cout << "Different.\n";
  }
}

int main() {
  Derived d;
  // pd 指向派生类
  Derived* pd = &d;

  // pb1 是指向基类B1的指针
  B1* pb1 = static_cast<B1*>(&d);
  Compare(pd, pb1);  // Same.

  // pb2 是指向基类B1的指针
  B2* pb2 = static_cast<B2*>(&d);
  Compare(pd, pb2);  // Different.

  void* derived_plus_offset = (char*)pd + sizeof(B1);
  Compare(derived_plus_offset, pb2);  // Same.
  return 0;
}
