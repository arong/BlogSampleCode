#include <chrono>
#include <execution>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  std::vector<int> data(1'000'000, 1);

  // 串行归约操作并计时
  auto start_seq = std::chrono::high_resolution_clock::now();
  int sum_seq = std::accumulate(data.begin(), data.end(), 0);
  auto end_seq = std::chrono::high_resolution_clock::now();
  std::cout << "串行归约耗时: "
            << std::chrono::duration_cast<std::chrono::milliseconds>(end_seq -
                                                                     start_seq)
                   .count()
            << " ms" << std::endl;

  // 并行归约操作并计时
  auto start_par = std::chrono::high_resolution_clock::now();
  int sum_par = std::reduce(std::execution::par, data.begin(), data.end(), 0);
  auto end_par = std::chrono::high_resolution_clock::now();
  std::cout << "并行归约耗时: "
            << std::chrono::duration_cast<std::chrono::milliseconds>(end_par -
                                                                     start_par)
                   .count()
            << " ms" << std::endl;
  return 0;
}
