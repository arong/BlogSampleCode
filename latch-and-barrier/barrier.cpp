#include <barrier>
#include <chrono>
#include <iostream>
#include <syncstream>
#include <thread>
#include <vector>

void phase_work(std::barrier<>& barrier, int id) {
  for (char phase = 'A'; phase < 'D'; ++phase) {
    // 模拟当前阶段的工作
    std::this_thread::sleep_for(std::chrono::milliseconds(100 * id));

    // 等待所有线程完成当前阶段
    std::osyncstream(std::cout)
        << "线程 " << id << " 完成了任务 " << phase << ". \n";
    barrier.arrive_and_wait();
  }
}

int main() {
  constexpr int num_threads = 5;
  std::barrier barrier(num_threads);

  std::vector<std::thread> threads;
  for (int i = 0; i < num_threads; ++i) {
    threads.emplace_back([&barrier, i]() { phase_work(barrier, i + 1); });
  }

  for (auto& t : threads) {
    t.join();
  }

  return 0;
}
