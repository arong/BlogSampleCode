#include <atomic>
#include <iostream>

class Counter {
 public:
  Counter(int id) : counter_(id) {}

  void Reset(int cnt) { counter_.store(cnt); }

  int Get() { return counter_.load(); }

  int Increase() { return counter_++; }

  int IncreaseBy(int cnt) { return counter_.fetch_add(cnt) + cnt; }

  int DecreaseBy(int cnt) { return counter_.fetch_sub(cnt) - cnt; }

 private:
  std::atomic<int> counter_;
};

int main() {
  Counter counter(0);
  counter.Increase();
  counter.IncreaseBy(10);
  counter.DecreaseBy(5);
  std::cout << "Counter: " << counter.Get() << std::endl;

  return 0;
}