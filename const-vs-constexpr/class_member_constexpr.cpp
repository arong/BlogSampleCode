class MyClass {
 public:
  // 表示该函数不修改成员变量, 且可以在编译时求值
  constexpr int size() const { return size_; }

 private:
  int size_ = 0;
};
