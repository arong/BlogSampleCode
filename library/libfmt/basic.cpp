#include <fmt/chrono.h>
#include <fmt/core.h>

#include <chrono>

int main() {
  // 1. 基础
  fmt::println("Hello {} from year {}", "World", 2025);
  // 输出: Hello World from year 2025

  // 2. 指定参数位置
  fmt::println("{0}+{0}={1}", 1, 2);              // 输出: 1+1=2
  fmt::println("{0}{1}{0} {1}{0}{1}", 'a', 'b');  // 输出: aba bab

  // 3. 整数格式化
  // 数用不同的基数表示整数, 类似printf中的 %d, %o
  fmt::println("decimal: {0:d}; hex: {0:x};  oct: {0:o}; binary: {0:b}", 42);
  // 输出: decimal: 42; hex: 2a;  oct: 52; binary: 101010

  // with 0x or 0 or 0b as prefix:
  fmt::println("decimal: {0:d}; hex: {0:#x};  oct: {0:#o}; binary: {0:#b}", 42);
  // 输出: decimal: 42; hex: 0x2a;  oct: 052; binary: 0b101010

  // 指定宽度
  fmt::println("{:#06x}", 0);  // 输出: 0x0000

  // 4. 浮点数格式化
  fmt::println("{:.{}f}", 3.14, 1);  // 输出: 3.1

  // Replacing % +f, % -f, and % f and specifying a sign :
  fmt::println("{:+f}; {:+f}", 3.14, -3.14);  // 输出: +3.140000; -3.140000

  // show a space for positive numbers
  fmt::println("{: f}; {: f}", 3.14, -3.14);  // 输出: " 3.140000; -3.140000"

  // show only the minus -- same as '{:f}; {:f}'
  fmt::println("{:-f}; {:-f}", 3.14, -3.14);  // 输出: 3.140000; -3.140000

  // 5. 对齐和宽度
  // 左对齐
  fmt::println("{:<30}", "left aligned");
  // 输出: "left aligned                  "

  // 右对齐
  fmt::println("{:>30}", "right aligned");
  // 输出: "                 right aligned"

  // 居中对其, 空格填充
  fmt::println("{:^30}", "centered");
  // 输出: "           centered           "

  // 居中对其, 使用'*'字符对齐
  fmt::println("{:*^30}", "centered");  // 使用 '*' 作为填充字符
  // 输出: "***********centered***********"

  // 动态宽度
  int width = 30;
  fmt::println("{:*^{}}", "centered", width);
  // 输出: "***********centered***********"

  // 6. 时间
  std::tm datetime = {};
  datetime.tm_year = 2025 - 1900;            // 年份从 1900 开始计数
  datetime.tm_mon = 1 - 1;                   // 月份从 0 开始计数
  datetime.tm_mday = 30;                     // 日期
  datetime.tm_hour = 12;                     // 小时
  datetime.tm_min = 12;                      // 分钟
  datetime.tm_sec = 30;                      // 秒
  fmt::println("time: {:%H:%M}", datetime);  // 输出: time: 12:12
  fmt::println("datetime: {:%Y-%m-%d %H:%M:%S}", datetime);
  // 输出: datetime: 2025-01-30 12:12:30

  // 7. 画出ASCII图
  fmt::print(
      "┌{0:─^{2}}┐\n"
      "│{1: ^{2}}│\n"
      "└{0:─^{2}}┘\n",
      "", "Hello, world!", 20);

  return 0;
}
