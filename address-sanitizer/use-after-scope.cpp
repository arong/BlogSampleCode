#include <iostream>
#include <string>

int main() {
  std::string* ptr;
  {
    std::string local_str = "hello";
    ptr = &local_str;
  }  // local_str超出作用域
  std::cout << *ptr << std::endl;  // 使用无效指针
  return 0;
}
