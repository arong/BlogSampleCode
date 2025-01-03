#include <chrono>
#include <coroutine>
#include <exception>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

class StringTask {
 public:
  struct promise_type {
    std::string result;

    auto return_value(const auto& value) { result = value; }
    auto get_return_object() {
      return std::coroutine_handle<promise_type>::from_promise(*this);
    }
    auto initial_suspend() { return std::suspend_always{}; }
    auto final_suspend() noexcept { return std::suspend_always{}; }
    void unhandled_exception() { std::terminate(); }
  };

 private:
  std::coroutine_handle<promise_type> coroHdl;

 public:
  StringTask(auto h) : coroHdl{h} {}

  ~StringTask() {
    if (coroHdl) {
      coroHdl.destroy();
    }
  }

  // no copying, but moving is supported
  StringTask(StringTask const&) = delete;
  StringTask(StringTask&& rhs) : coroHdl(rhs.coroHdl) { rhs.coroHdl = nullptr; }
  StringTask& operator=(StringTask const&) = delete;

  bool resume() const {
    if (!coroHdl) {
      return false;
    }

    coroHdl.resume();
    return !coroHdl.done();
  }

  std::string getResult() const { return coroHdl.promise().result; }
};

StringTask computeInSteps() {
  std::string ret;

  ret += "Hello";
  co_await std::suspend_always();

  ret += " World";
  co_await std::suspend_always();

  ret += "!";
  co_return ret;
}

int main() {
  using namespace std::literals;

  StringTask task = computeInSteps();

  while (task.resume()) {
    std::this_thread::sleep_for(1s);
  }

  std::cout << "result: " << task.getResult() << '\n';
  return 0;
}
