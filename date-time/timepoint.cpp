#include <chrono>
#include <cmath>
#include <format>
#include <iostream>
#include <ratio>

int main() {
  auto now = std::chrono::system_clock::now();

  auto future = now + std::chrono::hours(1);   // 当前时间点加一小时
  auto past = now - std::chrono::minutes(30);  // 当前时间点减30分钟

  auto duration = future - now;  // 得到时间间隔
  std::cout
      << std::chrono::duration_cast<std::chrono::minutes>(duration).count()
      << " minutes\n";  // 60 minutes

  auto now_c = std::chrono::system_clock::to_time_t(now);
  std::cout << "Current time: "
            << std::ctime(&now_c);  // Current time: Wed Jan 22 18:12:17 2025

  using namespace std::chrono;
  time_point<steady_clock, seconds> tp_second{42s};
  // 从秒转为毫秒
  time_point<steady_clock, milliseconds> tp_milliseconds{tp_second};
  std::cout << tp_milliseconds.time_since_epoch().count() << "ms\n";  // 42000ms

  return 0;
}
