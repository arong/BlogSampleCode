#include <algorithm>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

struct Record {
  std::string primary;
  std::string secondary;
};

int main() {
  std::vector<Record> records = {{"A", "1"}, {"B", "0"}, {"a", "2"}};

  // also support ranges
  std::ranges::sort(records, [](const Record& p1, const Record& p2) {
    auto toLower = [](char c) { return std::tolower(c); };
    return std::ranges::lexicographical_compare(p1.primary, p2.primary,
                                                std::less{}, toLower, toLower);
  });

  for (const auto& record : records) {
    std::cout << record.primary << " " << record.secondary << std::endl;
  }
  return 0;
}
