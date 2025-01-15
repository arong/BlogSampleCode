#include <iostream>
#include <random>

void fill(float* p, size_t size) {
  std::random_device rd;   // 非确定性随机数生成器，用于种子
  std::mt19937 gen(rd());  // 基于 Mersenne Twister 的伪随机生成器
  std::uniform_real_distribution<> dis(0.0, 1.0);
  for (size_t i = 0; i < size; i++) {
    p[i] = dis(gen);
  }
}

int main() {
  float a[1024], b[1024];
  // 使用随机数填充数组a和b
  fill(a, 1024);
  fill(b, 1024);

  // 假设我们仍要进行加法操作
  float c[1024];
  for (int i = 0; i < 1024; ++i) {
    c[i] = a[i] + b[i];
  }

  // 输出结果的一部分，检查运行情况
  std::cout << "c[0] = " << c[0] << std::endl;
  return 0;
}
