#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec;
  if (!vec.empty()) {
    printf("vec not empty.\n");  // 死代码，因为条件始终为真
  }
}
