#include <chrono>
#include <coroutine>
#include <print>
#include <thread>

// Promise 模板类，用于管理协程的状态和生命周期
template <typename T>
struct Promise {
  // 获取返回对象的方法
  auto get_return_object() {
    std::println("Promise::get_return_object()");
    // 从当前 promise 创建一个协程句柄
    return std::coroutine_handle<Promise<T>>::from_promise(*this);
  }

  // 初始挂起点，在协程开始时调用
  auto initial_suspend() {
    std::println("Promise::initial_suspend()");
    // 返回一个总是挂起的挂起点
    return std::suspend_always{};
  }

  // 最终挂起点，在协程结束时调用
  auto final_suspend() noexcept {
    std::println("Promise::final_suspend()");
    // 返回一个总是挂起的挂起点
    return std::suspend_always{};
  }

  // 处理未捕获的异常
  void unhandled_exception() { std::terminate(); }

  // 返回 void 类型的方法
  void return_void() { std::println("Promise::return_void()"); }
};

// Task 类，表示一个协程任务
class Task {
 public:
  // 定义 promise_type 为 Promise<Task>
  using promise_type = Promise<Task>;

  // 构造函数，接受一个协程句柄
  Task(auto h) : handle_{h} { std::println("Task::construct"); }

  // 析构函数，销毁协程句柄
  ~Task() {
    std::println("Task::destruct");
    if (handle_) {
      handle_.destroy();
    }
  }

  // 恢复协程的方法
  bool resume() const {
    std::println("Task::resume()");
    if (!handle_) {
      return false;
    }
    handle_.resume();
    return !handle_.done();
  }

 private:
  // 协程句柄，管理协程的执行
  std::coroutine_handle<promise_type> handle_;
};

// GetTask 函数定义了一个协程任务
// 协程在调用 GetTask() 时创建，并在 co_await 处挂起
Task GetTask() {
  std::println("One!");
  co_await std::suspend_always{};  // 协程在此处第一次挂起

  std::println("Two!");
  co_await std::suspend_always{};  // 协程在此处第二次挂起

  std::println("Three!");
}

int main() {
  Task task = GetTask();
  std::println("coroutine GetTask() started");

  while (task.resume()) {
    using namespace std::literals;  // 为了使用 ms 后缀
    std::this_thread::sleep_for(500ms);
  }
  return 0;
}
