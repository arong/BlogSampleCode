#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec = {1, 2, 3, 5, 6};
  for (auto &item : vec) {
    if (item == 3) {
      vec.insert(vec.begin(), 4);
    }
    std::cout << item << std::endl;
  }
  return 0;
}