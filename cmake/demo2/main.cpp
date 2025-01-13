#include <fmt/core.h>
#include <fmt/ranges.h>

#include <iostream>
#include <map>
#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5};
  std::map<std::string, std::string> table = {{"name", "cmake"},
                                              {"function", "build"}};

  fmt::println("vec is: {}", vec);
  fmt::println("table is: {}", table);
  return 0;
}
