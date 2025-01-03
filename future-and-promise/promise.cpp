#include <future>
#include <iostream>
#include <thread>

void calculate(std::promise<int>& promise) {
  int result = 42;
  promise.set_value(result);
}

int main() {
  // 1. 创建 promise 和 future
  std::promise<int> promise;
  std::future<int> future = promise.get_future();

  // 2. 异步执行任务
  std::thread t(calculate, std::ref(promise));

  // 3. 获取结果
  int result = future.get();
  std::cout << "result: " << result << std::endl;

  t.join();
  return 0;
}