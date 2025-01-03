#include <algorithm>

class MyString {
 private:
  char* data;
  size_t length;

 public:
  // 移动构造函数
  MyString(MyString&& other) noexcept : data(other.data), length(other.length) {
    other.data = nullptr;  // 防止析构时释放原资源
    other.length = 0;
  }

  // 移动赋值运算符
  MyString& operator=(MyString&& other) noexcept {
    if (this != &other) {
      delete[] data;  // 释放已有资源
      data = other.data;
      length = other.length;
      other.data = nullptr;  // 防止析构时释放原资源
      other.length = 0;
    }
    return *this;
  }

  // 拷贝构造函数
  MyString(const MyString& other)
      : data(new char[other.length]), length(other.length) {
    std::copy(other.data, other.data + other.length, data);
  }

  // 析构函数
  ~MyString() { delete[] data; }
};
