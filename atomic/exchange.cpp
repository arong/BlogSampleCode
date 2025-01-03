#include <atomic>
#include <functional>
#include <memory>
#include <thread>

struct Task {
  std::atomic<bool> engaged;
  std::function<void()> task;
};

void GetTask(Task* task) {
  // exchange 的返回值是 task->engaged 的原始值
  if (task->engaged.exchange(true)) {
    // 如果 task 返回 true, 说明 task 已经被别的线程获取
  } else {
    // 如果 task 返回 false, 说明 task 被当前线程获取
    task->task();
  }
}
