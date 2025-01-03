#include <future>
#include <iostream>

int compute(int a, int b) { return a + b; }

int main() {
  // 使用函数启动异步任务
  std::future<int> result = std::async(compute, 2, 3);

  // 使用 lambda 表达式启动异步任务
  std::future<int> lambdaResult = std::async([]() { return 42; });

  std::cout << "Result: " << result.get() << std::endl;
  std::cout << "Lambda Result: " << lambdaResult.get() << std::endl;

  return 0;
}