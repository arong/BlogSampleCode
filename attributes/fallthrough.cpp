#include <iostream>
#include <string>

enum class TokenType { Integer, Float, String, Identifier };

void processToken(TokenType type, const std::string& token) {
  switch (type) {
    case TokenType::Integer:
      // 验证是否为有效整数
      [[fallthrough]];
    case TokenType::Float:
      // 对数值类型进行通用处理
      std::cout << "Processing numeric token: " << token << '\n';
      break;

    case TokenType::String:
      // 处理字符串
      if (token.empty()) {
        return;
      }
      [[fallthrough]];
    case TokenType::Identifier:
      // 字符串和标识符的共同处理逻辑
      std::cout << "Processing text token: " << token << '\n';
      break;
  }
}

int main() {
  processToken(TokenType::Float, "0.1");
  return 0;
}
