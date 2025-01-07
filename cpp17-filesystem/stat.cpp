#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main() {
  fs::path filePath = "example.txt";
  if (fs::exists(filePath)) {
    std::cout << "文件大小: " << fs::file_size(filePath) << " 字节\n";
    std::cout << "是否为正解文件: " << fs::is_regular_file(filePath) << "\n";
    std::cout << "文件最后修改时间: "
              << fs::last_write_time(filePath).time_since_epoch().count()
              << "\n";
  }
  return 0;
}
