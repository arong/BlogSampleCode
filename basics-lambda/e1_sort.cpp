#include <algorithm>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

struct Record {
  std::string primary;
  std::string secondary;
};

bool LessRecord(const Record& p1, const Record& p2) {
  return p1.primary < p2.primary ||
         (p1.primary == p2.primary && p1.secondary < p2.secondary);
}

int main() {
  std::vector<Record> records = {{"A", "1"}, {"B", "0"}, {"a", "2"}};
  // before
  std::sort(records.begin(), records.end(), LessRecord);

  // after
  std::sort(records.begin(), records.end(),
            [](const Record& p1, const Record& p2) {
              return p1.primary < p2.primary ||
                     (p1.primary == p2.primary && p1.secondary < p2.secondary);
            });

  // also support ranges
  std::ranges::sort(records, [](const Record& p1, const Record& p2) {
    return p1.primary < p2.primary ||
           (p1.primary == p2.primary && p1.secondary < p2.secondary);
  });

  for (const auto& record : records) {
    std::cout << record.primary << " " << record.secondary << std::endl;
  }
  return 0;
}
