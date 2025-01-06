#include <barrier>
#include <iostream>
#include <syncstream>
#include <thread>
#include <vector>

void worker(std::barrier<>& barrier, int id) {
  // 任务A
  std::this_thread::sleep_for(std::chrono::milliseconds(100 + id * 100));
  std::osyncstream(std::cout) << "线程 " << id << " 完成了任务 A. \n";
  barrier.arrive_and_wait();

  // 任务B
  std::this_thread::sleep_for(std::chrono::milliseconds(100 + id * 100));
  std::osyncstream(std::cout) << "线程 " << id << " 完成了任务 B. \n";
  barrier.arrive_and_wait();

  // 任务C
  std::this_thread::sleep_for(std::chrono::milliseconds(100 + id * 100));
  std::osyncstream(std::cout) << "线程 " << id << " 完成了任务 C. \n";
  barrier.arrive_and_wait();
}

int main() {
  constexpr int num_threads = 5;
  std::barrier barrier(num_threads);

  std::vector<std::thread> threads;
  for (int i = 0; i < num_threads; ++i) {
    threads.emplace_back(worker, std::ref(barrier), i + 1);
  }

  for (auto& t : threads) {
    t.join();
  }

  return 0;
}
