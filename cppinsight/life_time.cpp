#include <iostream>
#include <vector>

struct Bucket {
  std::vector<std::vector<int>> v;
};

Bucket createBucket() {
  return Bucket{{
      {1, 2, 3},
      {4, 5, 6},
  }};
}

int main() {
  for (auto vec : createBucket().v) {
    for (auto e : vec) {
      std::cout << e << ", ";
    }
    std::cout << "\n";
  }
  for (auto e : createBucket().v[0]) {
    std::cout << e << ',';
  }
  return 0;
}
