#include <chrono>
#include <iostream>
#include <stop_token>
#include <syncstream>
#include <thread>
#include <vector>

using namespace std::chrono_literals;

void download_task(std::stop_token token, int id) {
  int progress = 0;
  while (progress < 100) {
    if (token.stop_requested()) {
      std::osyncstream(std::cout)
          << "[任务 " << id << "] 检测到取消请求, 停止下载.\n";
      return;
    }

    std::this_thread::sleep_for(200ms);
    progress += 10;
    std::osyncstream(std::cout)
        << "[任务 " << id << "] 当前进度: " << progress << "%\n";
  }

  std::osyncstream(std::cout) << "[任务 " << id << "] 下载完成!\n";
}

int main() {
  // 控制多个线程的退出
  std::stop_source source;

  std::vector<std::jthread> tasks;
  for (int i = 0; i < 3; i++) {
    tasks.emplace_back(download_task, source.get_token(), i);
  }

  std::this_thread::sleep_for(1s);
  std::cout << "[主线程] 取消所有任务.\n";
  source.request_stop();  // 发出取消信号

  return 0;
}
