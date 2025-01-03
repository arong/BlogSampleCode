#include <atomic>
#include <iostream>
#include <thread>

int main() {
  std::atomic<int> x(1);
  std::atomic<int> y(2);

  std::jthread t1([&]() {
    y.store(4, std::memory_order_relaxed);
    x.store(3, std::memory_order_relaxed);
  });

  std::jthread t2([&]() {
    std::cout << x.load(std::memory_order_relaxed) << std::endl;
    std::cout << y.load(std::memory_order_relaxed) << std::endl;
  });

  return 0;
}