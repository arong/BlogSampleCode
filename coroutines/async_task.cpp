#include <coroutine>
#include <future>
#include <iostream>
#include <thread>

struct Task {
  struct promise_type {
    std::suspend_never initial_suspend() { return {}; }
    std::suspend_always final_suspend() noexcept { return {}; }
    Task get_return_object() { return Task{}; }
    void return_void() {}
    void unhandled_exception() { std::terminate(); }
  };
};

Task async_print() {
  std::cout << "Start async operation\n";
  co_await std::suspend_always{};
  std::cout << "Resume async operation\n";
}

int main() {
  auto task = async_print();
  std::cout << "Doing other work\n";
  return 0;
}
