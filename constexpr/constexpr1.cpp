#include <array>
#include <vector>
int main() {
  constexpr int size = 10;

  // 声明非常量类型
  int c_array[size] = {0};            // OK
  std::array<int, size> array = {0};  // OK
  std::vector<int> vec(size);         // OK

  // 声明常量类型
  constexpr int cpr_array_[size] = {0};             // OK
  constexpr std::array<int, size> cpr_array = {0};  // OK
  //   constexpr std::vector<int> cpr_vec(size);  // Error, std::vector
  //   不支持常量构造函数

  return 0;
}
