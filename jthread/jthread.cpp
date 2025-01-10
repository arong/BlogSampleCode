#include <iostream>
#include <syncstream>
#include <thread>

void task(int i) {
  std::osyncstream(std::cout) << "Task " << i << " done" << std::endl;
}

int main() {
  std::jthread t1(task, 1);
  std::jthread t2(task, 2);

  return 0;
}
