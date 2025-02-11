#include <fmt/ranges.h>

#include <algorithm>
#include <vector>

void forEachSample() {
  std::vector v = {1, 2, 3, 4, 5};
  // for_each
  std::for_each(v.begin(), v.end(), [](int& n) { n *= 2; });
  fmt::println("{}", v);  // [2, 4, 6, 8, 10]

  // ranges::for_each (C++20)
  std::ranges::for_each(v, [](int& n) { n = 1; });
  fmt::println("{}", v);  // [1, 1, 1, 1, 1]
}

void ForEachNSample() {
  std::vector  v = {1, 2, 3, 4, 5};
  // for_each_n (C++17)
  std::for_each_n(v.begin(), 3, [](int& n) { n = 2; });
  fmt::println("{}", v);  // [2, 2, 2, 1, 1]

  // ranges::for_each_n (C++20)
  std::ranges::for_each_n(v.begin(), 2, [](int& n) { n = 3; });
  fmt::println("{}", v);  // [3, 3, 2, 1, 1]
}

int main() {
  forEachSample();
  ForEachNSample();
  return 0;
}
