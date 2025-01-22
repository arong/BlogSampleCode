#include <iostream>
#include <ratio>

int main() {
  using r1 = std::ratio<1, 60>;  // 代表 1/60
  using r2 = std::ratio<1, 2>;   // 代表 1/2

  std::cout << r1::num << "/" << r1::den << "\n";

  // arithmetic
  using r3 = std::ratio<1, 2>;
  using r4 = std::ratio<1, 3>;

  using r5 = std::ratio_add<r3, r4>;       // 5/6
  using r6 = std::ratio_subtract<r3, r4>;  // 1/6
  using r7 = std::ratio_multiply<r3, r4>;  // 1/6
  using r8 = std::ratio_divide<r3, r4>;    // 3/2

  std::cout << r5::num << "/" << r5::den << "\n";
  std::cout << r6::num << "/" << r6::den << "\n";
  std::cout << r7::num << "/" << r7::den << "\n";
  std::cout << r8::num << "/" << r8::den << "\n";

  // compare
  using r9 = std::ratio<1, 3>;
  using r10 = std::ratio<2, 6>;
  std::cout << std::boolalpha << std::ratio_equal<r9, r10>::value
            << std::endl;  // true

  using atto = std::ratio<1, 1'000'000'000'000'000'000>;
  using femto = std::ratio<1, 1'000'000'000'000'000>;
  using pico = std::ratio<1, 1'000'000'000'000>;
  using nano = std::ratio<1, 1'000'000'000>;
  using micro = std::ratio<1, 1'000'000>;
  using milli = std::ratio<1, 1'000>;
  using centi = std::ratio<1, 100>;
  using deci = std::ratio<1, 10>;
  using deca = std::ratio<10, 1>;
  using hecto = std::ratio<100, 1>;
  using kilo = std::ratio<1'000, 1>;
  using mega = std::ratio<1'000'000, 1>;
  using giga = std::ratio<1'000'000'000, 1>;
  using tera = std::ratio<1'000'000'000'000, 1>;
  using peta = std::ratio<1'000'000'000'000'000, 1>;
  using exa = std::ratio<1'000'000'000'000'000'000, 1>;

  return 0;
}
