#include <iostream>
#include <string>

constexpr int square(int x) { return x * x; }
constexpr int strlen(std::string s) { return s.size(); }
constexpr std::string s = "hello";
constexpr int size = strlen(s);

int main() {
  std::cout << size << std::endl;
  return square(0);
}
