#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main() {
  // 1. 路径组合
  fs::path base = "/home/user/documents";
  fs::path file = "report.pdf";
  fs::path fullPath = base / file;  // 使用 / 操作符组合路径
  std::cout << "组合路径: " << fullPath << std::endl;
  // 输出: 组合路径: "/home/user/documents/report.pdf"

  fs::path filepath = "/home/user/documents/report.pdf";
  std::cout << "文件名: " << filepath.filename() << std::endl;
  std::cout << "主文件名: " << filepath.stem() << std::endl;
  std::cout << "扩展名: " << filepath.extension() << std::endl;
  std::cout << "父路径: " << filepath.parent_path() << std::endl;

  fs::path p1 = "/home/user/documents";
  fs::path p2 = "/home/user/pictures";
  fs::path rel = fs::relative(p2, p1);  // 计算从 p1 到 p2 的相对路径
  std::cout << "相对路径: " << rel << std::endl;  // ../pictures

  // 4. 路径分解与迭代
  fs::path complex = "/home/user/documents/work/report.pdf";
  std::cout << "路径分解:" << std::endl;
  for (const auto& part : complex) {
    std::cout << "  " << part << std::endl;
  }

  // 5. 路径规范化
  fs::path messy = "home/user/../user/./documents/report.pdf";
  std::cout << "规范化路径: " << messy.lexically_normal() << std::endl;

  // 6. 路径比较
  fs::path p3 = "documents/report.pdf";
  fs::path p4 = "documents/report.pdf";
  std::cout << "路径相等: " << (p3 == p4) << std::endl;

  // 使用 std::filesystem::equivalent 检查两个路径是否指向同一文件
  fs::path linkPath =
      "link_to_report.pdf";  // 假设这是一个指向 report.pdf 的符号链接
  fs::path actualPath = "documents/report.pdf";
  try {
    if (fs::equivalent(linkPath, actualPath)) {
      std::cout << "路径 " << linkPath << " 和 " << actualPath
                << " 指向同一文件." << std::endl;
    } else {
      std::cout << "路径 " << linkPath << " 和 " << actualPath
                << " 不指向同一文件." << std::endl;
    }
  } catch (const fs::filesystem_error& e) {
    std::cerr << "文件系统错误: " << e.what() << std::endl;
  }

  // 7. 路径拼接
  fs::path prefix = "backup_";
  fs::path filename = "report.pdf";
  fs::path newPath = prefix.string() + filename.string();
  std::cout << "拼接路径: " << newPath << std::endl;

  // 8. 检查路径特性
  fs::path checkPath = "/home/user/documents/report.pdf";
  std::cout << "是否为绝对路径: " << checkPath.is_absolute() << std::endl;
  std::cout << "是否有扩展名: " << checkPath.has_extension() << std::endl;
  std::cout << "是否有文件名: " << checkPath.has_filename() << std::endl;
  std::cout << "是否有父路径: " << checkPath.has_parent_path() << std::endl;

  // 9. 路径替换操作
  fs::path modPath = "/home/user/documents/report.pdf";
  modPath.replace_filename("newreport.doc");
  std::cout << "替换文件名后: " << modPath << std::endl;
  modPath.replace_extension(".txt");
  std::cout << "替换扩展名后: " << modPath << std::endl;

  return 0;
}
