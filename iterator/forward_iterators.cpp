#include <iostream>
#include <unordered_map>

int main() {
  std::unordered_map<int, int> map{{1, 2}, {3, 4}, {5, 6}};
  auto it = map.begin();
  it++;

  //   it--; // Error
  std::cout << it->first << ": " << it->second << std::endl;  // 3: 4
}
