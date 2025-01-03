#include <string>
#include <vector>

std::string GetStr() { return "Hello"; }
int main() {
  std::vector<std::string> vec;
  auto s = GetStr();

  vec.emplace_back(s);             // copy
  vec.emplace_back(s + "World");   // move
  vec.emplace_back(GetStr());      // move
  vec.emplace_back(std::move(s));  // move
  return 0;
}
