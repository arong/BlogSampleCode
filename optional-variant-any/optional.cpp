#include <iostream>
#include <optional>
#include <vector>

std::optional<int> findIndex(const std::vector<int>& vec, int target) {
  for (size_t i = 0; i < vec.size(); ++i) {
    if (vec[i] == target) return i;
  }
  return std::nullopt;  // 返回空值
}

std::optional<std::string> readFile(const std::string& path) {
  if (path.empty()) return std::nullopt;

  return "File content here...";
}

int main() {
  auto result = findIndex({1, 2, 3, 4}, 3);
  if (result) {
    std::cout << "Found at index: " << *result << std::endl;
  } else {
    std::cout << "Not found." << std::endl;
  }
  return 0;
}
