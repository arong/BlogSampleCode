#include <chrono>
#include <iostream>

int main() {
  using namespace std::chrono;

  auto today{floor<days>(system_clock::now())};
  system_clock::time_point t1{today};

  year_month_day date4{floor<days>(t1)};
  return 0;
}
