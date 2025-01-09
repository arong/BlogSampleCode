#include <flat_map>
#include <iostream>

int main() {
  std::flat_map<int, std::string> fmap;

  // 插入元素
  fmap.emplace(3, "three");
  fmap.emplace(1, "one");
  fmap.emplace(2, "two");

  // 遍历元素（有序）
  for (const auto& [key, value] : fmap) {
    std::cout << key << ": " << value << "\n";
  }

  // 查找元素
  if (fmap.contains(2)) {
    std::cout << "Key 2 found: " << fmap.at(2) << "\n";
  }

  return 0;
}
