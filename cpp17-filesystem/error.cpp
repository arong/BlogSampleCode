#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main() {
  try {
    fs::remove("non_existent.txt");
  } catch (const fs::filesystem_error& e) {
    std::cout << "错误: " << e.what() << std::endl;
  }
  return 0;
}
