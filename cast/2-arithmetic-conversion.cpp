#include <iostream>
#include <vector>

void print(const std::vector<int>& vec) {
  for (int i = 0; i < vec.size(); i++) {
    std::cout << i << ",";
  }
}

int main() {
  std::vector<int> v{1, 2, 3, 4, 5};
  print(v);
  return 0;
}
