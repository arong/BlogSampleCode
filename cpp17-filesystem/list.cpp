
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main() {
  fs::path dirPath = ".";  // 当前目录
  for (const auto& entry : fs::recursive_directory_iterator(dirPath)) {
    std::cout << entry.path() << std::endl;
  }
  return 0;
}
