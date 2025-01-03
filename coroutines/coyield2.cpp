#include <cassert>
#include <coroutine>
#include <exception>
#include <iostream>
#include <thread>
#include <vector>

class IntRange {
 public:
  struct promise_type {
    int currentValue = 0;

    auto yield_value(int value) {
      currentValue = value;
      return std::suspend_always{};
    }
    auto get_return_object() {
      return std::coroutine_handle<promise_type>::from_promise(*this);
    }
    auto initial_suspend() { return std::suspend_always{}; }
    auto final_suspend() noexcept { return std::suspend_always{}; }
    void unhandled_exception() { std::terminate(); }
    void return_void() {}
  };

 private:
  std::coroutine_handle<promise_type> coroHdl;

 public:
  IntRange(auto h) : coroHdl{h} {}

  ~IntRange() {
    if (coroHdl) {
      coroHdl.destroy();
    }
  }

  // no copying, but moving is supported
  IntRange(IntRange const&) = delete;
  IntRange(IntRange&& rhs) : coroHdl(rhs.coroHdl) { rhs.coroHdl = nullptr; }
  IntRange& operator=(IntRange const&) = delete;

  struct iterator {
    std::coroutine_handle<promise_type> hdl;
    iterator(auto p) : hdl{p} {}

    void getNext() {
      if (hdl) {
        hdl.resume();
        if (hdl.done()) {
          hdl.done();
        }
      }
    }

    int operator*() const {
      assert(hdl != nullptr);
      return hdl.promise().currentValue;
    }
    iterator operator++() {
      getNext();
      return *this;
    }
    bool operator==(const iterator& i) const = default;
  };

  iterator begin() const {
    if (!coroHdl || coroHdl.done()) {
      return iterator{nullptr};
    }
    iterator itor{coroHdl};
    itor.getNext();
    return itor;
  }
  iterator end() const { return iterator{nullptr}; }
};

template <typename T>
IntRange loopOver(const T& coll) {
  for (int elem : coll) {
    std::cout << "- suspend " << "\n";
    co_yield elem;
    std::cout << "- resume\n";
  }
}

int main() {
  using namespace std::literals;

  std::vector<int> coll{0, 8, 15, 33, 42, 77};
  IntRange gen = loopOver(coll);

  std::cout << "start loop:\n";
  for (const auto& val : gen) {
    std::cout << "value: " << val << '\n';
    std::this_thread::sleep_for(1s);
  }
  return 0;
}
