#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  auto make_interest_func = [](double rate) {
    return [rate](double principal) { return principal * (1 + rate); };
  };

  // 创建一个计算 5% 利息的函数
  auto calculate_interest = make_interest_func(0.05);
  std::cout << "Amount with interest: " << calculate_interest(100) << '\n';
  return 0;
}
