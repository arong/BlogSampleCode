#include <coroutine>
#include <iostream>
#include <optional>

struct Generator {
  struct promise_type {
    int current_value;
    std::suspend_always yield_value(int value) {
      current_value = value;
      return {};
    }
    std::suspend_always initial_suspend() { return {}; }
    std::suspend_always final_suspend() noexcept { return {}; }
    Generator get_return_object() { return Generator{this}; }
    void return_void() {}
    void unhandled_exception() { std::terminate(); }
  };

  struct iterator {
    std::coroutine_handle<promise_type> coro;
    bool operator!=(std::default_sentinel_t) const { return !coro.done(); }
    iterator& operator++() {
      coro.resume();
      return *this;
    }
    int operator*() const { return coro.promise().current_value; }
  };

  iterator begin() {
    handle.resume();
    return iterator{handle};
  }
  std::default_sentinel_t end() { return {}; }

 private:
  explicit Generator(promise_type* p)
      : handle(std::coroutine_handle<promise_type>::from_promise(*p)) {}
  std::coroutine_handle<promise_type> handle;
};

Generator generate_numbers(int start, int end) {
  for (int i = start; i <= end; ++i) {
    co_yield i;
  }
}

int main() {
  for (int value : generate_numbers(1, 5)) {
    std::cout << value << " ";
  }
  return 0;
}
