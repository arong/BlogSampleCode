struct A {};
struct B {};

int main() {
  float f = 7.406f;
  int i = (int)f;             // int i = static_cast<int>(f);
  A* pa = (A*)&f;             // A* pa = reinterpret_cast<A*>(&f);
  B* pb = (B*)pa;             // B* pb = reinterpret_cast<B*>(pa);
  double d = *(double*)(pb);  // double d = *reinterpret_cast<double*>((pb));

  return 0;
}
