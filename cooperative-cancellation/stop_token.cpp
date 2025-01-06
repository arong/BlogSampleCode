#include <chrono>
#include <iostream>
#include <stop_token>
#include <thread>

using namespace std::chrono_literals;

void download_file(std::stop_token token) {
  int progress = 0;
  while (progress < 100) {
    if (token.stop_requested()) {
      std::cout << "[下载任务] 检测到取消请求, 停止下载.\n";
      return;
    }

    std::this_thread::sleep_for(200ms);
    progress += 1;
    std::cout << "[下载任务] 当前进度: " << progress << "%\n";
  }
  std::cout << "[下载任务] 下载完成!\n";
}

int main() {
  std::jthread downloader(download_file);

  std::this_thread::sleep_for(1s);

  std::cout << "[主线程] 取消下载任务.\n";
  downloader.request_stop();  // 发出取消信号

  return 0;
}
