#include <exception>
#include <iostream>

void cf() {
  try {
    throw std::runtime_error("An error occurred");
  } catch (std::exception ex) {  // 😱 按值捕获会创建副本,
                                 // 并且可能会出现类切分(class slicing)
    std::cerr << "Caught exception by value: " << ex.what() << std::endl;
  }
}

void cg() {
  try {
    throw std::runtime_error("An error occurred");
  } catch (const std::exception& ex) {  // 推荐的引用捕获方式
    std::cerr << "Caught exception by reference: " << ex.what() << std::endl;
  }
}

int main() {
  cf();
  cg();
  return 0;
}
