#include <atomic>
#include <chrono>
#include <iostream>
#include <random>
#include <thread>
#include <vector>

std::atomic<unsigned long int> leader_id(-1);

void try_to_be_leader() {
  // 生成一个 100 到 1000 毫秒之间的随机睡眠时间
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(100, 1000);
  int sleep_duration = dis(gen);

  // 休眠随机时间, 模拟线程执行任务
  std::this_thread::sleep_for(std::chrono::milliseconds(sleep_duration));

  auto thread_id = std::this_thread::get_id();
  unsigned long int expected = -1;
  // 尝试成为 leader
  if (leader_id.compare_exchange_strong(
          expected, std::hash<std::thread::id>{}(thread_id))) {
    std::cout << "Thread " << thread_id << " became the leader." << std::endl;
  } else {
    std::cout << "Thread " << thread_id << " failed." << std::endl;
  }
}

int main() {
  constexpr int kNumThreads = 10;
  std::vector<std::jthread> threads;

  for (int i = 0; i < kNumThreads; ++i) {
    threads.emplace_back(try_to_be_leader);
  }

  std::cout << "Leader is: " << leader_id.load() << std::endl;
  return 0;
}