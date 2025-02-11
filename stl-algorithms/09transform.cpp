#include <fmt/ranges.h>

#include <algorithm>
#include <array>
#include <vector>

int main() {
  const std::array v = {1, 2, 3, 4, 5};
  std::vector<int> result(v.size());

  // 使用 transform 将每个元素乘以 2 并存储到 result 中
  std::transform(v.begin(), v.end(), result.begin(),
                 [](int num) { return num * 2; });
  // 输出 transform 的结果
  fmt::println("transform: {}", result);

  // 使用 ranges::transform 做同样的操作
  std::vector<int> resultRanges(v.size());
  std::ranges::transform(v, resultRanges.begin(),
                         [](int num) { return num * 2; });
  // 输出 ranges::transform 的结果
  fmt::println("ranges::transform: {}", resultRanges);

  return 0;
}
