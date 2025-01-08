#include <string>

class Widget {
 public:
  template <typename Self>
  auto&& GetData(this Self&& self) {
    // 根据对象是左值还是右值返回相应的引用类型
    return std::forward<Self>(self).data;
  }

 private:
  std::string data;
};

int main() {
  Widget w1;
  const Widget w2;

  auto& ref = w1.GetData();          // 自动推导左值
  const auto& cref = w2.GetData();   // 自动推导 const 左值
  auto&& rref = Widget{}.GetData();  // 自动推导右值

  return 0;
}
