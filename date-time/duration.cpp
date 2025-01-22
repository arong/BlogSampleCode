#include <chrono>
#include <format>
#include <iostream>
#include <ratio>

int main() {
  std::chrono::duration<long, std::ratio<1, 1>> d1;
  std::chrono::duration<long, std::ratio<1>> d2;
  std::chrono::duration<long> d3;

  std::chrono::duration<long, std::ratio<60>> d4;

  std::chrono::duration<long, std::ratio<1>> d5{14};  // = 14 seconds
  ++d5;                                               // = 15 seconds
  d5 *= 2;                                            // = 30 seconds

  std::chrono::duration<long, std::ratio<60>> d6{10};  // = 10 minutes
  if (d5 > d6) {
    std::cout << "d5 > d6" << std::endl;
  } else {
    std::cout << "d5 <= d6" << std::endl;
  }

  // Add both durations and store as minutes.
  std::chrono::duration<double, std::ratio<60>> d7{d5 + d6};
  // Add both durations and store as seconds.
  std::chrono::duration<long, std::ratio<1>> d8{d5 + d6};
  std::cout << std::format("{}min + {}sec = {}min or {}sec", d6.count(),
                           d5.count(), d7.count(),
                           d8.count())
            << std::endl;  // 10min + 30sec = 10.5min or 630sec

  std::chrono::duration<long> d9{30};                     // = 30 seconds
  std::chrono::duration<double, std::ratio<60>> d10{d9};  // = 0.5 minutes
  std::cout << std::format("{}sec = {}min", d9.count(),
                           d10.count())
            << std::endl;  // 30sec = 0.5min

  // Force conversion (0 instead of 0.5)
  auto d11{
      duration_cast<std::chrono::duration<long, std::ratio<60>>>(d9)};  // = 0

  // 使用预定义的单位
  std::chrono::minutes d12{1};
  // 使用字面量
  using namespace std::literals::chrono_literals;
  auto d13{1min};
  std::cout << std::boolalpha << (d12 == d13) << std::endl;  // true
  auto d14{std::chrono::hours{1} + std::chrono::minutes{23} +
           std::chrono::seconds{45}};     // 5025 seconds
  std::cout << d14.count() << std::endl;  // 5025

  return 0;
}
