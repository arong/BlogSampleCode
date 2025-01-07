#include <algorithm>
#include <chrono>
#include <execution>
#include <iostream>
#include <random>
#include <vector>

int main() {
  // 生成随机数据集
  constexpr size_t kTotalCount = 1'000'000;
  std::vector<int> data(kTotalCount);
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(1, kTotalCount);
  for (auto& d : data) {
    d = dis(gen);
  }

  // 串行排序并计时
  auto start_seq = std::chrono::high_resolution_clock::now();
  std::sort(data.begin(), data.end());
  auto end_seq = std::chrono::high_resolution_clock::now();
  std::cout << "串行排序耗时: "
            << std::chrono::duration_cast<std::chrono::milliseconds>(end_seq -
                                                                     start_seq)
                   .count()
            << " ms" << std::endl;

  // 打乱数据顺序
  std::shuffle(data.begin(), data.end(), gen);

  // 并行排序并计时
  auto start_par = std::chrono::high_resolution_clock::now();
  std::sort(std::execution::par, data.begin(), data.end());
  auto end_par = std::chrono::high_resolution_clock::now();
  std::cout << "并行排序耗时: "
            << std::chrono::duration_cast<std::chrono::milliseconds>(end_par -
                                                                     start_par)
                   .count()
            << " ms" << std::endl;

  std::shuffle(data.begin(), data.end(), gen);

  // 矢量化排序并计时
  auto start_unseq = std::chrono::high_resolution_clock::now();
  std::sort(std::execution::unseq, data.begin(), data.end());
  auto end_unseq = std::chrono::high_resolution_clock::now();
  std::cout << "矢量化排序耗时: "
            << std::chrono::duration_cast<std::chrono::milliseconds>(
                   end_unseq - start_unseq)
                   .count()
            << " ms" << std::endl;

  std::shuffle(data.begin(), data.end(), gen);

  // 并行且矢量化排序并计时
  auto start_par_unseq = std::chrono::high_resolution_clock::now();
  std::sort(std::execution::par_unseq, data.begin(), data.end());
  auto end_par_unseq = std::chrono::high_resolution_clock::now();
  std::cout << "并行且矢量化排序耗时: "
            << std::chrono::duration_cast<std::chrono::milliseconds>(
                   end_par_unseq - start_par_unseq)
                   .count()
            << " ms" << std::endl;
  return 0;
}
