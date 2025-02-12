#include <iostream>
#include <type_traits>

// 检查是否有 begin 方法
template <typename T>
class has_begin {
 private:
  template <typename U>
  static auto check(int)
      -> decltype(std::declval<U>().begin(), std::true_type());

  template <typename>
  static std::false_type check(...);

 public:
  static constexpr bool value = decltype(check<T>(0))::value;
};

int main() {
  std::cout << has_begin<std::string>::value << std::endl;  // 输出 1
  std::cout << has_begin<int>::value << std::endl;          // 输出 0
  return 0;
}
