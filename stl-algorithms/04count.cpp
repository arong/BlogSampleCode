#include <fmt/core.h>

#include <algorithm>
#include <array>

void Count() {
  constexpr std::array v = {1, 2, 3, 3, 4, 5};

  // count
  fmt::println("Count of 3: {}", std::count(v.begin(), v.end(), 3));
  // Count of 3: 2

  // ranges::count
  fmt::println("Count of 3 (ranges): {}", std::ranges::count(v, 3));
  // Count of 3 (ranges): 2
}

void CountIf() {
  constexpr std::array v = {1, 2, 3, 3, 4, 5};
  // count_if
  fmt::println("Count of elements greater than 3: {}",
               std::count_if(v.begin(), v.end(), [](int n) { return n > 3; }));
  // Count of elements greater than 3: 2

  // ranges::count_if
  fmt::println("Count of elements greater than 3 (ranges): {}\n",
               std::ranges::count_if(v, [](int n) { return n > 3; }));
  // Count of elements greater than 3 (ranges): 2
}

int main() {
  Count();
  CountIf();
  return 0;
}
