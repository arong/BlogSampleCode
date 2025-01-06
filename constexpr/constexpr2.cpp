#include <string>
#include <string_view>

int main() {
  constexpr double root_of_2 = 1.41421356237;     // OK
  constexpr const char* hello = "Hello, World!";  // OK
  constexpr std::string_view str_view{hello};     // OK
  constexpr std::string str{hello};               // Error
  return 0;
}
