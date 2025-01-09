#include <string>

[[nodiscard("file fd")]] int openFile(const std::string& path) {
  int fd = -1;
  // ....
  return fd;
}

int main() {
  openFile("a.txt");               // 编译器警告: 返回值被忽略
  int result = openFile("b.txt");  // 正确使用, 无警告
  return 0;
}
