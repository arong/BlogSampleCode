#include <iostream>

template <typename T>
void choose(T a) {
  if constexpr (std::is_integral_v<T>) {
    std::cout << "integer \n";
  } else {
    std::cout << "other type\n";
  }
}

int main() {
  choose(0);
  choose("hello");
  return 0;
}
