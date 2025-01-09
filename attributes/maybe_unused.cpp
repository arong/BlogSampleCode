#include <source_location>
#include <string>

class Logger {
 public:
  void log([[maybe_unused]] const std::string& message,
           [[maybe_unused]] int severity,
           [[maybe_unused]] const std::source_location& location =
               std::source_location::current()) {
#ifdef DEBUG_BUILD
    std::cout << "[" << severity << "] " << location.function_name() << ": "
              << message << '\n';
#endif
  }
};

template <typename T>
class [[maybe_unused]] DebugAllocator {
  // 仅在调试构建中使用的特殊分配器实现
};

int main() {
  Logger logger;
  logger.log("Starting application", 1);
  return 0;
}
