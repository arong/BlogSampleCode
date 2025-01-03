#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5, 6};

  double sum = 0.0;
  std::for_each(vec.begin(), vec.end(), [&sum](double d) { sum += d; });

  std::cout << "Total: " << sum << '\n';
  return 0;
}
