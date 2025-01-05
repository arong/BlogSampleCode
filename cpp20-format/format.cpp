#include <print>

int main() {
  // basic
  std::println("{} + {} = {}", 2, 3, 2 + 3);  // 输出：2 + 3 = 5
  std::println();

  // width and alignment
  std::println("|{:>10}|", "right");   // 右对齐：|     right|
  std::println("|{:<10}|", "left");    // 左对齐：|left      |
  std::println("|{:^10}|", "center");  // 居中对齐：|  center  |
  std::println("|{:-^10}|", "fill");   // 居中填充：|--fill---|
  std::println();

  // digit format
  std::println("Decimal: {}", 42);     // 十进制：Decimal: 42
  std::println("Hex: {:#x}", 255);     // 十六进制：Hex: 0xff
  std::println("Octal: {:#o}", 255);   // 八进制：Octal: 0377
  std::println("Binary: {:#b}", 255);  // 二进制：Binary: 0b11111111
  std::println("Padded: {:08}", 42);   // 填充：Padded: 00000042
  std::println();

  std::println("Default    : {}", 3.14159);       // 默认：3.14159
  std::println("Fixed      : {:.2f}", 3.14159);   // 保留两位小数：3.14
  std::println("Scientific : {:.2e}", 3.14159);   // 科学计数法：3.14e+00
  std::println("Width      : {:8.2f}", 3.14159);  // 宽度 8：    3.14
  std::println();

  return 0;
}
