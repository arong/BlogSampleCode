#include <iostream>

// 类模板的定义
template <typename T>
class Box {
 private:
  T data;

 public:
  Box(T value) : data(value) {}
  void display() { std::cout << "Box Value: " << data << std::endl; }
};

int main() {
  Box<int> intBox(100);
  Box<std::string> strBox("Hello, Template!");

  intBox.display();
  strBox.display();
  return 0;
}
