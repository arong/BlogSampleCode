#include <fmt/base.h>
#include <fmt/core.h>
#include <fmt/os.h>
#include <fmt/ostream.h>
#include <fmt/printf.h>

#include <iostream>
int main() {
  // printf
  // 用fmt::printf替换
  fmt::fprintf(stderr, "Hello from %s!\n", "fmt::printf");
  // 输出: Hello from fmt::printf!

  // 改写
  auto s = fmt::format("Hello from {}!", "fmt::format");
  fmt::println(s);  // 输出: Hello from fmt::format!

  // 与ostream的搭配
  fmt::println(std::cerr, "Don't {}!", "panic");  // 输出: Don't panic!

  // 替代 fstream
  auto out = fmt::output_file("greeting.txt");
  out.print("Hello {}!", "World");

  // 替代: ostringstream
  auto buffer = fmt::memory_buffer();
  fmt::format_to(std::back_inserter(buffer), "width:{};", 480);
  fmt::format_to(std::back_inserter(buffer), "height:{};", 360);
  fmt::println(buffer.data());  // 输出: width:480;height:360;
  return 0;
}
