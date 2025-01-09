#include <string>

struct [[nodiscard]] Error {
  int code;
  std::string message;
};

Error generateError() {
  // Simulate an error with a code and message
  return {404, "Resource not found"};
}

int main() {
  // Ignoring the error would lead to missing important error handling
  generateError();

  return 0;
}
