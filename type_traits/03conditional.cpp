#include <iostream>
#include <list>
#include <type_traits>
#include <vector>

// 根据类型是否为整型选择不同的容器类型
template <typename T>
using ContainerType =
    std::conditional_t<std::is_integral<T>::value,
                       std::vector<T>,  // 如果 T 是整型，使用 std::vector
                       std::list<T>     // 如果 T 不是整型，使用 std::list
                       >;

int main() {
  // 整型，使用 std::vector
  ContainerType<int> c1 = {1, 2, 3, 4, 5};
  static_assert(std::is_same<std::vector<int>, decltype(c1)>::value);

  // 非整型，使用 std::list
  ContainerType<double> c2 = {1.1, 2.2, 3.3, 4.4, 5.5};
  static_assert(std::is_same<std::list<double>, decltype(c2)>::value);

  return 0;
}
