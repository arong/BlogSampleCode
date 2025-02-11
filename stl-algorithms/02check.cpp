#include <fmt/ranges.h>

#include <algorithm>
#include <ranges>

void AllOf() {
  constexpr std::array v = {1, 2, 3, 4, 5};
  // all_of
  fmt::println("All elements greater than 0: {}",
               std::all_of(v.begin(), v.end(), [](int n) { return n > 0; }));
  // ranges::all_of (C++20)
  fmt::println("All elements greater than 1: {}",
               std::ranges::all_of(v, [](int n) { return n > 1; }));
}

void AnyOf() {
  constexpr std::array v = {1, 2, 3, 4, 5};
  // any_of
  fmt::println("Any element greater than 4: {}",
               std::any_of(v.begin(), v.end(), [](int n) { return n > 4; }));
  // ranges::any_of (C++20)
  fmt::println("Any element greater than 6: {}",
               std::ranges::any_of(v, [](int n) { return n > 6; }));
}

void NoneOf() {
  constexpr std::array v = {1, 2, 3, 4, 5};
  // none_of
  fmt::println("None of the elements greater than 6: {}",
               std::none_of(v.begin(), v.end(), [](int n) { return n > 6; }));
  // ranges::none_of (C++20)
  fmt::println("None of the elements greater than 2: {}",
               std::ranges::none_of(v, [](int n) { return n > 2; }));
}

int main() {
  AllOf();
  AnyOf();
  NoneOf();
  return 0;
}