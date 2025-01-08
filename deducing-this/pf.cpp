#include <string>
class Widget {
 public:
  std::string& GetData() & { return data; }

  const std::string& GetData() const& { return data; }

  std::string&& GetData() && { return std::move(data); }

 private:
  std::string data;
};

int main() {
  Widget w1;
  const Widget w2;

  std::string& ref = w1.GetData();          // 调用左值版本
  const std::string& cref = w2.GetData();   // 调用 const 左值版本
  std::string&& rref = Widget{}.GetData();  // 调用右值版本

  return 0;
}
