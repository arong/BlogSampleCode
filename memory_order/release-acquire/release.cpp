#include <atomic>
#include <iostream>
#include <thread>

int main() {
  std::atomic<int> x(0);
  std::atomic<int> y(0);

  std::jthread t1([&]() {
    y.store(2, std::memory_order_release);
    x.store(1, std::memory_order_release);
  });

  std::jthread t2([&]() {
    std::cout << x.load(std::memory_order_acquire) << std::endl;
    std::cout << y.load(std::memory_order_acquire) << std::endl;
  });

  return 0;
}