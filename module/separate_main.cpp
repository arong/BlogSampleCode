import demo;

#include <iostream>
#include <vector>

int main() {
  std::vector vec{1, 2, 3, 4, 5};
  std::cout << "sum  : " << demo::sum(vec) << std::endl;
  std::cout << "prod : " << demo::prod(vec) << std::endl;
}
