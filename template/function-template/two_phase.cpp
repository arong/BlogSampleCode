template <typename T>
void example(T a) {
  a.undefinedFunction();  // 仅在实例化时检查
}

int main() { return 0; }
