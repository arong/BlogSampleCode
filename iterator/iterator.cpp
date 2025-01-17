#include <iostream>
#include <vector>

void remove(std::vector<int>& vec, int target) {
  for (auto it = vec.begin(); it != vec.end(); it++) {
    if (*it == target) {
      vec.erase(it);
    }
  }
}

int main() {
  std::vector<int> vec{10, 20, 30, 40};
  for (auto it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << " ";
  }
  // 输出: 10 20 30 40
  std::cout << std::endl;

  for (size_t i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl;

  auto p = vec.data();
  for (size_t i = 0; i < vec.size(); i++) {
    std::cout << p[i] << " ";
  }
  std::cout << std::endl;
}
