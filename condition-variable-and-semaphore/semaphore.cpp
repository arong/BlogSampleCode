#include <chrono>
#include <iostream>
#include <queue>
#include <semaphore>
#include <thread>

class ThreadSafeQueue {
 private:
  std::queue<int> buffer;
  std::mutex mtx;
  std::counting_semaphore<> notFull;
  std::counting_semaphore<> notEmpty;

 public:
  explicit ThreadSafeQueue(unsigned int size) : notFull(size), notEmpty(0) {}

  void produce(int item) {
    notFull.acquire();  // Wait until there's space in the queue
    {
      std::lock_guard<std::mutex> lock(mtx);
      buffer.push(item);
      std::cout << "生产: " << item << " (缓冲区大小: " << buffer.size() << ")"
                << std::endl;
    }
    notEmpty.release();  // Signal that an item is available
  }

  int consume() {
    notEmpty.acquire();  // Wait until there's an item in the queue
    int item;
    {
      std::lock_guard<std::mutex> lock(mtx);
      item = buffer.front();
      buffer.pop();
      std::cout << "消费: " << item << " (缓冲区大小: " << buffer.size() << ")"
                << std::endl;
    }
    notFull.release();  // Signal that space is available
    return item;
  }
};

int main() {
  ThreadSafeQueue queue(5);

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
