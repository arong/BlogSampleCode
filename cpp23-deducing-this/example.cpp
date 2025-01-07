class Example {
  void traditional_method() {
    // 传统方式：this的类型是隐式的 Example*
  }

  void explicit_this(this Example& self) {
    // 新语法：显式声明this参数
  }
};
