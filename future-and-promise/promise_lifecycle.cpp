#include <future>
#include <iostream>

int main() {
  std::promise<int> promiseObj;
  std::future<int> futureObj = promiseObj.get_future();

  try {
    // 没有调用 set_value
    int result = futureObj.get();
  } catch (const std::future_error& e) {
    std::cout << "Future error: " << e.what() << std::endl;
  }

  return 0;
}
