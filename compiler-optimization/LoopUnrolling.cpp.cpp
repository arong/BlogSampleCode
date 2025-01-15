#include <iostream>
#include <random>

void get(int* p, size_t size) {
  // 创建随机数引擎
  std::random_device rd;   // 用于获得种子
  std::mt19937 gen(rd());  // 标准 mersenne_twister_engine seeded with rd()

  // 创建均匀分布的随机数生成器，范围从0到99
  std::uniform_int_distribution<> dis(0, 99);
  for (int i = 0; i < size; i++) {
    p[i] = dis(gen);
  }
}

int main() {
  // 生成并打印 8 个随机数
  int array[8] = {0};
  get(array, 8);

  int sum = 0;
  for (int i = 0; i < 8; i++) {
    sum += array[i];
  }

  std::cout << sum << std::endl;

  return 0;
}
