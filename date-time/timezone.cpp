#include <chrono>
#include <iostream>

int main() {
  using namespace std::chrono;
  const auto& database{get_tzdb()};
  for (const auto& timezone : database.zones) {
    std::cout << timezone.name() << std::endl;
  }

  auto* hk{locate_zone("Asia/Hong_Kong")};
  auto* gmt{locate_zone("GMT")};
  auto* current{current_zone()};

  auto now = system_clock::now();
  auto gm_now = gmt->to_local(now);
  std::cout << gm_now << std::endl;

  zoned_time zt{hk, now};
  std::cout << "Current time in HongKong: " << zt << '\n';
  return 0;
}
