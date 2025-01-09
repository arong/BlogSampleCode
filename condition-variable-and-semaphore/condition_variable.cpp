#include <chrono>
#include <condition_variable>
#include <iostream>
#include <queue>
#include <thread>

class ThreadSafeQueue {
 private:
  std::queue<int> buffer;
  const unsigned int maxSize;
  std::mutex mtx;
  std::condition_variable notFull;
  std::condition_variable notEmpty;

 public:
  explicit ThreadSafeQueue(unsigned int size) : maxSize(size) {}

  void produce(int item) {
    std::unique_lock<std::mutex> lock(mtx);
    // 等待队列不满
    notFull.wait(lock, [this] { return buffer.size() < maxSize; });

    buffer.push(item);
    std::cout << "生产: " << item << " (缓冲区大小: " << buffer.size() << ")"
              << std::endl;

    // 通知消费者
    notEmpty.notify_one();
  }

  int consume() {
    std::unique_lock<std::mutex> lock(mtx);
    // 等待队列不空
    notEmpty.wait(lock, [this] { return !buffer.empty(); });

    int item = buffer.front();
    buffer.pop();
    std::cout << "消费: " << item << " (缓冲区大小: " << buffer.size() << ")"
              << std::endl;

    // 通知生产者
    notFull.notify_one();
    return item;
  }
};

int main() {
  ThreadSafeQueue queue(3);

  auto producer = [&queue]() {
    for (int i = 0; i < 10; ++i) {
      queue.produce(i);
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
  };

  auto consumer = [&queue]() {
    for (int i = 0; i < 10; ++i) {
      queue.consume();
      std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
  };

  std::jthread producerThread(producer);
  std::jthread consumerThread(consumer);
  return 0;
}
