module demo;

#include <numeric>
#include <vector>

namespace demo {
int sum(const std::vector<int>& v) {
  return std::accumulate(v.begin(), v.end(), 1, std::plus{});
}

int prod(const std::vector<int>& v) {
  return std::accumulate(v.begin(), v.end(), 1, std::multiplies{});
}
}  // namespace demo
