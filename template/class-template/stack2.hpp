#pragma once
#include <cstddef>
#include <cstdint>
#include <stdexcept>

// 模板类 Array 的一般实现
template <typename T, size_t N = 10>
class Stack {
 private:
  T* data_ = nullptr;
  size_t capacity_ = N;
  size_t length_ = 0;

  void resize(size_t new_capacity) {
    T* new_data = new T[new_capacity];
    for (size_t i = 0; i < length_; ++i) {
      new_data[i] = data_[i];
    }
    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
  }

 public:
  Stack() { data_ = new T[capacity_]; }

  ~Stack() { delete[] data_; }

  void Push(const T& value) {
    if (length_ == capacity_) {
      resize(capacity_ * 2);
    }
    data_[length_++] = value;
  }

  void Pop() {
    if (length_ == 0) {
      throw std::out_of_range("Index out of range");
    }
    --length_;
  }

  [[nodiscard]] size_t Size() const { return length_; }

  [[nodiscard]] bool Empty() const { return length_ == 0; }

  T Top() const {
    if (0 == length_) {
      throw std::out_of_range("Index out of range");
    }
    return data_[length_ - 1];
  }
};

// 针对 bool 类型的特化实现
template <size_t N>
class Stack<bool, N> {
 private:
  uint8_t* data_ = nullptr;
  size_t capacity_ = 10;
  size_t length_ = 0;

  void resize(size_t new_capacity) {
    auto* new_data = new uint8_t[new_capacity];
    for (size_t i = 0; i < length_; ++i) {
      new_data[i] = data_[i];
    }
    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
  }

 public:
  Stack() { data_ = new uint8_t[(capacity_ + 7) / 8]; }
  ~Stack() { delete[] data_; }

  [[nodiscard]] size_t Size() const { return length_; }
  [[nodiscard]] bool Empty() const { return length_ == 0; }

  void Push(bool value) {
    if (length_ == capacity_) {
      resize(capacity_ * 2);
    }
    size_t byte_index = length_ / 8;
    size_t bit_index = length_ % 8;
    if (value) {
      data_[byte_index] |= (1 << bit_index);
    } else {
      data_[byte_index] &= ~(1 << bit_index);
    }
    ++length_;
  }

  void Pop() {
    if (0 == length_) {
      throw std::out_of_range("Index out of range");
    }
    --length_;
  }

  [[nodiscard]] bool Top() const {
    if (0 >= length_) {
      throw std::out_of_range("Index out of range");
    }
    size_t byte_index = (length_ - 1) / 8;
    size_t bit_index = (length_ - 1) % 8;
    uint8_t result = (data_[byte_index] >> bit_index) & 1;
    return result == 1;
  }
};

template <typename T, size_t N>
class Stack<T*, N> {
 private:
  T** data_ = nullptr;
  size_t capacity_ = 10;
  size_t length_ = 0;

  void resize(size_t new_capacity) {
    auto* new_data = new T*[new_capacity];
    for (size_t i = 0; i < length_; ++i) {
      new_data[i] = data_[i];
    }
    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
  }

 public:
  Stack() { data_ = new T*[capacity_]; }

  ~Stack() {
    for (size_t i = 0; i < length_; ++i) {
      delete data_[i];
    }
    delete[] data_;
  }
  void Push(T* value) {
    if (length_ == capacity_) {
      resize(capacity_ * 2);
    }
    data_[length_++] = value;
  }
  void Pop() { length_--; }
  T* Top() { return data_[length_ - 1]; }
  [[nodiscard]] size_t Size() const { return length_; }
  [[nodiscard]] bool Empty() const { return length_ == 0; }
};
