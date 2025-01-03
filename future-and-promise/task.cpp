#include <future>
#include <iostream>
#include <thread>

int main() {
  // 同步任务
  int res = 0;
  std::thread t([&res] { res = 42; });
  t.join();
  std::cout << "同步结果: res = " << res << std::endl;

  // 异步任务
  std::future<int> f = std::async([] { return 42; });
  std::cout << "异步结果: f.get() = " << f.get() << std::endl;

  return 0;
}