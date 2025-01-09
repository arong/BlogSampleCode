#include <compare>
#include <iostream>

class CaseInsensitiveString {
 private:
  std::string str;

  static std::string to_lower(const std::string& s) {
    std::string result = s;
    for (char& c : result) {
      c = std::tolower(c);
    }
    return result;
  }

 public:
  explicit CaseInsensitiveString(const std::string& s) : str(s) {}
  const std::string& get_string() const { return str; }

  std::weak_ordering operator<=>(const CaseInsensitiveString& other) const {
    // Compare lowercase versions of strings
    return to_lower(str) <=> to_lower(other.str);
  }
};

int main() {
  CaseInsensitiveString s1("Hello");
  CaseInsensitiveString s2("hello");
  CaseInsensitiveString s3("World");

  // Demonstrate weak equality
  std::cout << "s1: \"" << s1.get_string() << "\"\n";
  std::cout << "s2: \"" << s2.get_string() << "\"\n";
  std::cout << "s3: \"" << s3.get_string() << "\"\n\n";

  std::cout << std::boolalpha;
  // Even though s1 and s2 are different strings,
  // they are considered equal in weak equality comparison
  std::cout << "s1 == s2: " << (s1 <=> s2 == 0) << "\n";
  std::cout << "s1 == s3: " << (s1 <=> s3 == 0) << "\n";

  std::partial_ordering result = 1.0001 <=> 1.0002;  // result 表示 equivalent
  return 0;
}
