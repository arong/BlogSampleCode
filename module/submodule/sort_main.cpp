import sort;
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector v{5, 4, 3, 2, 1};
  sort::bubble_sort(v);
  std::cout << "sub module demo.\n"
            << "is sorted? " << std::boolalpha
            << std::is_sorted(v.begin(), v.end(), std::less{}) << std::endl;
  return 0;
}
