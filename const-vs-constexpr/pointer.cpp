int main() {
  const int* ptr = nullptr;   // 指针所指的值是常量
  int* const cptr = nullptr;  // 指针本身是常量

  int a = 0;
  const int c = 1;
  ptr = &a;  // OK
  ptr = &c;  // OK

  // ptr = 3;    // Error, 不能通过常量指针修改值
  // cptr = &a;  // Error, 不能改变指针指向
  // cptr = &c;  // Error, 不能改变指针指向
  return 0;
}
