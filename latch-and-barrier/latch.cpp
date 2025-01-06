#include <iostream>
#include <latch>
#include <random>
#include <syncstream>
#include <thread>
#include <vector>

void worker(std::latch& latch, int id) {
  // 使用 osyncstream 同步输出
  std::osyncstream(std::cout) << "线程 " << id << " 正在工作...\n";

  // 生成一个随机值, 范围为[100, 500]
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(100, 500);
  int sleep_duration = dis(gen);

  // sleep一段时间, 模拟工作
  std::this_thread::sleep_for(std::chrono::milliseconds(sleep_duration));

  // 发布完成信号并同步输出
  std::osyncstream(std::cout) << "线程 " << id << " 完成了任务. \n";

  latch.count_down();
}

int main() {
  constexpr int num_threads = 5;
  std::latch latch(num_threads);

  std::vector<std::thread> threads;
  for (int i = 0; i < num_threads; ++i) {
    threads.emplace_back(worker, std::ref(latch), i + 1);
  }

  // 等待所有线程完成任务
  latch.wait();
  std::cout << "所有线程已完成任务. \n";

  for (auto& t : threads) {
    t.join();
  }

  return 0;
}
