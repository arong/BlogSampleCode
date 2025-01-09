#include <cctype>
#include <compare>
#include <iostream>
#include <string>

class CaseInsensitiveString {
  std::string text;

 public:
  CaseInsensitiveString(const std::string& s) : text(s) {}

  // Weak ordering is appropriate here because "Hello" and "hello" are
  // equivalent but not necessarily equal
  std::weak_ordering operator<=>(const CaseInsensitiveString& other) const {
    auto it1 = text.begin();
    auto it2 = other.text.begin();

    while (it1 != text.end() && it2 != other.text.end()) {
      char c1 = std::tolower(*it1);
      char c2 = std::tolower(*it2);

      if (c1 < c2) return std::weak_ordering::less;
      if (c1 > c2) return std::weak_ordering::greater;

      ++it1;
      ++it2;
    }

    // Handle different lengths
    if (it1 == text.end() && it2 == other.text.end())
      return std::weak_ordering::equivalent;
    return (it1 == text.end()) ? std::weak_ordering::less
                               : std::weak_ordering::greater;
  }

  // For demonstration purposes
  const std::string& get_text() const { return text; }
};

// Example usage in main
int main() {
  CaseInsensitiveString s1("Hello");
  CaseInsensitiveString s2("hello");
  CaseInsensitiveString s3("World");

  // These strings are equivalent under weak ordering
  bool equivalent = (s1 <=> s2 == 0);
  std::cout << "比较 \"" << s1.get_text() << "\" 和 \"" << s2.get_text()
            << "\":\n";
  std::cout << "是否等价: " << (equivalent ? "是" : "否") << "\n\n";

  // But s1 and s3 have a clear ordering
  bool less = (s1 <=> s3 < 0);
  std::cout << "比较 \"" << s1.get_text() << "\" 和 \"" << s3.get_text()
            << "\":\n";
  std::cout << "s1 是否小于 s3: " << (less ? "是" : "否") << "\n\n";

  // 添加更多比较示例
  std::cout << "额外的比较示例:\n";
  std::cout << "\"" << s2.get_text() << "\" 大于 \"" << s3.get_text()
            << "\": " << ((s2 <=> s3 > 0) ? "是" : "否") << "\n";

  return 0;
}
