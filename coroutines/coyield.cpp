#include <coroutine>
#include <exception>
#include <iostream>
#include <print>
#include <thread>
#include <vector>

// Generator 类，表示一个生成器协程
class Generator {
 public:
  // promise_type 结构体，管理协程的状态和生命周期
  struct promise_type {
    int value_ = 0;  // 当前值

    // yield_value 方法，用于挂起协程并保存当前值
    auto yield_value(int value) {
      value_ = value;
      return std::suspend_always{};  // 总是挂起协程
    }

    // get_return_object 方法，返回协程句柄
    auto get_return_object() {
      return std::coroutine_handle<promise_type>::from_promise(*this);
    }

    // initial_suspend 方法，初始挂起点
    auto initial_suspend() { return std::suspend_always{}; }

    // final_suspend 方法，最终挂起点
    auto final_suspend() noexcept { return std::suspend_always{}; }

    // unhandled_exception 方法，处理未捕获的异常
    void unhandled_exception() { std::terminate(); }

    // return_void 方法，协程返回 void 类型
    void return_void() {}
  };

 public:
  // 构造函数，接受一个协程句柄
  Generator(auto h) : handle_{h} {}

  // 析构函数，销毁协程句柄
  ~Generator() {
    if (handle_) {
      handle_.destroy();
    }
  }

  // 恢复协程的方法
  bool resume() const {
    if (!handle_) {
      return false;
    }

    handle_.resume();
    return !handle_.done();
  }

  // 获取当前值的方法
  int getValue() const { return handle_.promise().value_; }

 private:
  // 协程句柄，管理协程的执行
  std::coroutine_handle<promise_type> handle_;
};

template <typename T>
Generator Visit(const T& coll) {
  for (int elem : coll) {
    std::println("\tyield {}", elem);
    co_yield elem;
    std::println("\tresume");
  }
}

int main() {
  using namespace std::literals;

  std::vector<int> coll{0, 8, 15, 33, 42, 77};
  Generator gen = Visit(coll);

  std::println("start loop:");
  while (gen.resume()) {
    std::println("main(): value: {}", gen.getValue());
    std::this_thread::sleep_for(1s);
  }
}
