#include <iostream>
#include <list>

int main() {
  std::list<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8};
  auto it = vec.begin();
  it++;
  std::cout << *it << std::endl;  // 1
  it--;
  std::cout << *it << std::endl;  // 0
}
