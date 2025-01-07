#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main() {
  fs::path symlinkPath = "symbolic_link";
  fs::path targetPath = "target_file";
  fs::create_symlink(targetPath, symlinkPath);  // 创建符号链接
  if (fs::is_symlink(symlinkPath)) {
    std::cout << symlinkPath << " 是符号链接, 指向 "
              << fs::read_symlink(symlinkPath) << std::endl;
  }
  return 0;
}
