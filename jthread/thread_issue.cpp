#include <iostream>
#include <syncstream>
#include <thread>

void task(int i) {
  std::osyncstream(std::cout) << "Task " << i << " done" << std::endl;
}
int main() {
  std::thread t1(task, 1);
  std::thread t2(task, 2);

  return 0;
}
