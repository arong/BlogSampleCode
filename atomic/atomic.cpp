#include <atomic>
#include <iostream>

std::atomic<int> counter{0}; // 定义一个原子变量并初始化为 0

int main() {
    std::cout << "Initial counter: " << counter.load() << std::endl;
    return 0;
}
