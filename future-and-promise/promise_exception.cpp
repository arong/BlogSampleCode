#include <future>
#include <iostream>
#include <stdexcept>
#include <thread>

void calculate(std::promise<int>& promise) {
  try {
    throw std::runtime_error("An error occurred!");
  } catch (...) {
    // 设置异常
    promise.set_exception(std::current_exception());
  }
}

int main() {
  std::promise<int> promise;
  std::future<int> futureObj = promise.get_future();

  std::thread t(calculate, std::ref(promise));

  try {
    // 这里会捕获异常
    int result = futureObj.get();
  } catch (const std::exception& e) {
    std::cout << "Caught exception: " << e.what() << std::endl;
  }

  t.join();
  return 0;
}
