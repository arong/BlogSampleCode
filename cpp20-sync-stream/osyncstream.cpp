#include <iostream>
#include <syncstream>  // 引入对应头文件
#include <thread>
#include <vector>

int main() {
  constexpr int num_thread = 10;
  std::vector<std::thread> threads;

  // 开启线程
  for (int i = 0; i < num_thread; i++) {
    threads.emplace_back(
        [](int id) {
          std::osyncstream(std::cout) << "Thread " << id << " is doing job\n";
        },
        i);
  }

  // 等待线程结束
  for (auto& t : threads) {
    t.join();
  }
  return 0;
}
