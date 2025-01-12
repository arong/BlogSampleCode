#include <stddef.h>

class my_array {
 public:
  char& operator[](size_t offset) {
    return const_cast<char&>(const_cast<const my_array&>(*this)[offset]);
  }
  const char& operator[](size_t offset) const { return buffer[offset]; }

 private:
  char buffer[10];
};
int main() {
  const my_array a{};
  const auto& c = a[4];
  my_array mod_a;
  mod_a[4] = 7;
  return 0;
}
