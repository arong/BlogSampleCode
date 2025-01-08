#include <iostream>
#include <vector>

class DataContainer {
 public:
  const std::vector<int>& GetData() const { return data; }
  std::vector<int>& GetData() { return data; }

 private:
  std::vector<int> data;
};

int main() {
  DataContainer dc;
  const DataContainer cdc;

  std::vector<int>& ref = dc.GetData();          // 获取非 const 数据引用
  const std::vector<int>& cref = cdc.GetData();  // 获取 const 数据引用

  return 0;
}
