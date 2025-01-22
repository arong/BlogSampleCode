#include <chrono>
#include <cmath>
#include <format>
#include <iostream>
#include <ratio>

int main() {
  // 获取开始时间
  auto start{std::chrono::high_resolution_clock::now()};
  // 模拟一些工作
  double d{0};
  for (int i{0}; i < 1'000'000; ++i) {
    d += sqrt(sin(i));
  }
  // 获取结束时间
  auto end{std::chrono::high_resolution_clock::now()};

  // 计算时间差
  auto diff{end - start};
  // 转为毫秒
  std::cout << std::chrono::duration<double, std::milli>{diff}.count()
            << "ms\n";
  return 0;
}
