#include <fmt/core.h>
#include <fmt/ranges.h>

#include <vector>

int main() {
  fmt::print("Hello world\n");

  std::vector<int> v = {1, 2, 3, 4, 5};
  fmt::println("v = {}\n", v);
  return 0;
}
