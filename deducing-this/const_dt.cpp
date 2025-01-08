#include <iostream>
#include <vector>
#include <utility>  // for std::as_const

class DataContainer {
 public:
  template <typename Self>
  auto&& GetData(this Self&& self) {
    if constexpr (std::is_const_v<std::remove_reference_t<Self>>) {
      return std::as_const(self.data);
    } else {
      return self.data;
    }
  }

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
