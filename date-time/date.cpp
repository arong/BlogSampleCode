#include <chrono>
#include <iostream>

int main() {
  using namespace std::chrono;

  year y{2025};
  month m{1};
  day d{21};
  year_month_day date{y, m, d};
  std::cout << date << std::endl;  // 2025-01-21

  auto date1 = {y / m / d};
  auto date2 = {d / m / y};

  year_month_day date3{Wednesday[4] / January / 2025};
  std::cout << date3 << std::endl;  // 2025-01-22

  auto next_month = date + months{1};  // 加一个月

  std::cout << std::format("{:%Y-%m-%d}\n", date);

  return 0;
}
