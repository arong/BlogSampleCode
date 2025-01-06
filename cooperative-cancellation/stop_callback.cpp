#include <chrono>
#include <fstream>
#include <iostream>
#include <stop_token>
#include <thread>

using namespace std::chrono_literals;

void download_file_with_cleanup(std::stop_token token) {
  std::ofstream file("output.txt", std::ios::out);

  // 定义回调函数：取消任务时关闭文件
  std::stop_callback callback(token, [&file] {
    std::cout << "[下载任务]-[回调] 检测到取消请求, 关闭文件句柄.\n";
    file.close();
  });

  int progress = 0;
  while (progress < 100) {
    if (token.stop_requested()) {
      std::cout << "[下载任务] 检测到取消请求, 停止下载.\n";
      return;
    }

    // 写入到文件
    file << "下载进度: " << progress << "%\n";

    std::cout << "[下载任务] 当前进度: " << progress << "%\n";
    std::this_thread::sleep_for(200ms);
    progress += 1;
  }

  file.close();
  std::cout << "[下载任务] 下载完成, 文件已保存.\n";
}

int main() {
  std::jthread downloader(download_file_with_cleanup);

  std::this_thread::sleep_for(1s);

  std::cout << "[主线程] 取消下载任务.\n";
  downloader.request_stop();  // 发出取消信号

  return 0;
}
