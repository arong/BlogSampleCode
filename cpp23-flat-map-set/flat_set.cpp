#include <flat_set>
#include <iostream>

int main() {
  std::flat_set<int> fset;

  // 插入元素
  fset.insert(5);
  fset.insert(3);
  fset.insert(4);

  // 遍历元素（有序）
  for (const auto& elem : fset) {
    std::cout << elem << " ";
  }
  std::cout << "\n";

  // 查找元素
  if (fset.contains(3)) {
    std::cout << "Element 3 is in the set\n";
  }

  return 0;
}
