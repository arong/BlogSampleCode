[[deprecated("Use newFunction instead")]]
void oldFunction() {}

void newFunction() {}

int main() {
  oldFunction();  // 警告: oldFunction 已弃用
  newFunction();  // 正确使用
  return 0;
}
