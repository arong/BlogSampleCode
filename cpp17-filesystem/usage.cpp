#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main() {
  fs::path filePath = "example.txt";
  if (fs::exists(filePath)) {
    std::cout << "文件存在!\n";
  } else {
    std::cout << "文件不存在.\n";
  }

  fs::path dirPath = "new_directory";
  fs::create_directory(dirPath);  // 创建单个目录
  fs::remove(dirPath);            // 删除目录

  fs::copy("source.txt", "destination.txt",
           fs::copy_options::overwrite_existing);  // 复制文件
  fs::rename("old_name.txt", "new_name.txt");      // 重命名文件
  return 0;
}
