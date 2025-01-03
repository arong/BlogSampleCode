#include <iostream>
#include <type_traits>

namespace std {
template <>
struct is_pointer<int> : public std::true_type  // defines a type trait as true
{};
}  // namespace std

int main() {
  bool var2 = std::is_pointer<int>::value;
  std::cout << std::boolalpha << std::is_pointer<int>::value << std::endl;
  return 0;
}