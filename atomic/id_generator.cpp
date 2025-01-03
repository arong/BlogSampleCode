#include <iostream>
#include <mutex>

class Counter {
 public:
  Counter(int id) : counter_(id) {}

  void Reset(int cnt) {
    std::lock_guard<std::mutex> lock(mutex_);
    counter_ = cnt;
  }

  int Increase() {
    std::lock_guard<std::mutex> lock(mutex_);
    return counter_++;
  }

  int IncreaseBy(int cnt) {
    std::lock_guard<std::mutex> lock(mutex_);
    counter_ += cnt;
    return counter_;
  }

  int DecreaseBy(int cnt) {
    std::lock_guard<std::mutex> lock(mutex_);
    counter_ -= cnt;
    return counter_;
  }

  int Get() {
    std::lock_guard<std::mutex> lock(mutex_);
    return counter_;
  }

 private:
  std::mutex mutex_;
  int counter_;
};
