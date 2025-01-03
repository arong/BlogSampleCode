#include <thread>
#include <vector>
#include <iostream>
#include <atomic>
#include <chrono>
#include <queue>
#include <condition_variable>
#include <functional>

class TaskManager {
public:
  TaskManager(int num_threads) : stop_flag(false) {
    for (int i = 0; i < num_threads; ++i) {
      consumers.emplace_back(&TaskManager::consumer, this, i + 1);
    }
  }

  ~TaskManager() {
    Stop();
    for (auto& t : consumers) {
      if (t.joinable()) {
        t.join();
      }
    }
  }

  void AddTask(std::function<void()> task) {
    {
      std::lock_guard<std::mutex> lock(queue_mutex);
      tasks.push(task);
    }
    cv.notify_one();
  }

  void Stop() {
    {
      std::lock_guard<std::mutex> lock(queue_mutex);
      stop_flag.store(true, std::memory_order_release);
    }
    cv.notify_all();
  }

private:
  void consumer(int id) {
    while (true) {
      std::function<void()> task;
      {
        std::unique_lock<std::mutex> lock(queue_mutex);
        cv.wait(lock, [this] { return !tasks.empty() || stop_flag.load(std::memory_order_acquire); });
        if (stop_flag.load(std::memory_order_acquire) && tasks.empty()) {
          break;
        }
        task = std::move(tasks.front());
        tasks.pop();
      }
      task();
      std::cout << "Consumer " << id << ": Task completed.\n";
    }
    std::cout << "Consumer " << id << ": Exiting.\n";
  }

  std::vector<std::thread> consumers;
  std::queue<std::function<void()>> tasks;
  std::mutex queue_mutex;
  std::condition_variable cv;
  std::atomic<bool> stop_flag;
};

int main() {
  TaskManager manager(3);

  manager.AddTask([] {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Task 1 executed.\n";
  });

  manager.AddTask([] {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Task 2 executed.\n";
  });

  std::this_thread::sleep_for(std::chrono::seconds(3));
  manager.Stop();

  return 0;
}