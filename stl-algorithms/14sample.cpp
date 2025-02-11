#include <fmt/ranges.h>

#include <algorithm>
#include <array>
#include <random>
#include <vector>

// 示例: sample, ranges::sample
void example_sample() {
  constexpr std::array v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> result(3);  // 抽样结果存储的容器

  // 创建随机数引擎
  std::random_device rd;
  std::mt19937 gen(rd());

  // 使用 std::sample
  std::sample(v.begin(), v.end(), result.begin(), 3, gen);
  fmt::println("std::sample: {}", result);

  // 使用 std::ranges::sample
  std::ranges::sample(v, result.begin(), 3, gen);
  fmt::println("std::ranges::sample: {}", result);
}

int main() {
  example_sample();
  return 0;
}
