#include <iostream>
#include <latch>
#include <syncstream>
#include <thread>
#include <vector>

void worker(std::latch& latchA, std::latch& latchB, std::latch& latchC,
            int id) {
  // 任务A
  std::this_thread::sleep_for(std::chrono::milliseconds(100 + id * 100));
  {
    std::osyncstream sync_out(std::cout);
    sync_out << "线程 " << id << " 完成了任务 A. \n";
  }
  latchA.arrive_and_wait();

  // 任务B
  std::this_thread::sleep_for(std::chrono::milliseconds(100 + id * 100));
  {
    std::osyncstream sync_out(std::cout);
    sync_out << "线程 " << id << " 完成了任务 B. \n";
  }
  latchB.arrive_and_wait();

  // 任务C
  std::this_thread::sleep_for(std::chrono::milliseconds(100 + id * 100));
  {
    std::osyncstream sync_out(std::cout);
    sync_out << "线程 " << id << " 完成了任务 C. \n";
  }
  latchC.arrive_and_wait();
}

int main() {
  constexpr int num_threads = 5;
  std::latch latchA(num_threads);
  std::latch latchB(num_threads);
  std::latch latchC(num_threads);

  std::vector<std::thread> threads;
  for (int i = 0; i < num_threads; ++i) {
    threads.emplace_back(worker, std::ref(latchA), std::ref(latchB),
                         std::ref(latchC), i + 1);
  }

  for (auto& t : threads) {
    t.join();
  }

  return 0;
}
