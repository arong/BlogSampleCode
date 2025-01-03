#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

int main() {
  std::atomic<bool> ready{false};

  std::jthread producer([&]() {
    std::cout << "Producer: Preparing data...\n";
    // 模拟数据准备
    std::this_thread::sleep_for(std::chrono::seconds(2));

    // 数据准备完毕
    ready.store(true);
    // 通知等待的线程
    ready.notify_one();

    std::cout << "Producer: Data ready.\n";
  });

  std::jthread consumer([&]() {
    // 等待直到 ready 为 true
    ready.wait(false);
    std::cout << "Consumer: Data received.\n";
  });

  return 0;
}
