#include <fmt/core.h>
#include <fmt/ranges.h>

#include <vector>

int main() {
  std::vector<int> vec = {1, 2, 3};
  fmt::print("Vector: [{}]\n",
             fmt::join(vec, ", "));  // 输出: Vector: [1, 2, 3]
  return 0;
}
