#include <atomic>
#include <iostream>
#include <thread>

std::atomic<int> sharedData{0};

void producer([[carries_dependency]] int* data) {
  *data = 42;                                      // Produce data
  sharedData.store(1, std::memory_order_release);  // Release the data
}

void consumer([[carries_dependency]] int* data) {
  while (sharedData.load(std::memory_order_acquire) != 1) {
    // Wait for the data to be produced
  }
  std::cout << "Consumed data: " << *data << '\n';  // Consume data
}

int main() {
  int data = 0;
  std::thread t1(producer, &data);
  std::thread t2(consumer, &data);

  t1.join();
  t2.join();

  return 0;
}
