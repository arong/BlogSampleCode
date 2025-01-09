#include <cstdlib>
#include <iostream>
#include <limits>

template <typename T>
class Vector {
 public:
  Vector() : data_(nullptr), size_(0) {}

  void resize(size_t newSize) {
    [[assume(newSize < std::numeric_limits<size_t>::max() / sizeof(T))]];
    T* newData = static_cast<T*>(std::realloc(data_, newSize * sizeof(T)));
    if (newData) {
      data_ = newData;
      size_ = newSize;
    } else {
      std::cerr << "Memory allocation failed\n";
      // Handle allocation failure
    }
  }

  T& operator[](size_t index) {
    [[assume(index < size_)]];  // Assume caller ensures valid index
    return data_[index];        // No need for boundary check
  }

  size_t size() const { return size_; }

  ~Vector() { std::free(data_); }

 private:
  T* data_;
  size_t size_;
};

int main() {
  Vector<int> vec;
  vec.resize(10);
  vec[0] = 42;
  std::cout << "First element: " << vec[0] << '\n';
  std::cout << "Vector size: " << vec.size() << '\n';

  return 0;
}
