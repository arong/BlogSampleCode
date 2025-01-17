#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8};
  auto it = vec.begin();
  it++;
  it += 3;
  std::cout << *it << std::endl;    // 4
  std::cout << it[0] << std::endl;  // 4

  auto it2 = vec.begin() + 6;
  std::cout << std::boolalpha << (it < it2) << std::endl;  // true
}
