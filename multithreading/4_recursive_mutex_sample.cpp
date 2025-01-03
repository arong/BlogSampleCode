#include <iostream>
#include <mutex>
#include <thread>

std::recursive_mutex rmutex;

void recursive_function(int count) {
  if (count <= 0) return;

  rmutex.lock();
  std::cout << "Thread " << std::this_thread::get_id()
            << " acquired lock at count " << count << std::endl;
  recursive_function(count - 1);
  rmutex.unlock();
}

int main() {
  std::jthread t1(recursive_function, 5);
  std::jthread t2(recursive_function, 5);
  return 0;
}