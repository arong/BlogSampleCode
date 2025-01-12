#include <cstddef>
#include <cstdint>
#include <iostream>

struct Struct {
  Struct(float f) : m_(f) {}
  float m_ = 0;
};

int main() {
  float f = -3.1415926;
  double d = f;
  int i = f;
  size_t s = f;
  char c = f;
  Struct st = f;

  std::cout << f << std::endl;
  std::cout << d << std::endl;
  std::cout << i << std::endl;
  std::cout << s << std::endl;
  std::cout << c << std::endl;
  std::cout << st.m_ << std::endl;
  return 0;
}
