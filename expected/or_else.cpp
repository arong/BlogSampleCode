#include <expected>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

std::expected<std::string, std::string> openFile(const std::string& file) {
  std::ifstream inFile(file, std::ios::in);

  namespace fs = std::filesystem;

  // 检查文件是否存在
  if (!fs::exists(file)) {
    return std::unexpected("File does not exist.");
  }

  if (!inFile.is_open()) {
    return std::unexpected("Failed to open file: ");  // 返回错误信息
  }

  // 读取文件内容
  std::ostringstream content;
  content << inFile.rdbuf();

  return content.str();  // 返回文件内容
}

int main() {
  auto handleFileError =
      [](const std::string& err) -> std::expected<std::string, std::string> {
    if (err == "File does not exist.") {
      return "Default file content";  // 试图读取默认文件
    }
    return std::unexpected(err);
  };

  auto content = openFile("somefile.txt").or_else(handleFileError);

  if (!content) {
    std::cerr << "Error: " << content.error() << std::endl;
  } else {
    std::cout << "Success: " << *content << std::endl;
  }
  return 0;
}
