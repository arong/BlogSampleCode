#include <fmt/core.h>
#include <fmt/ranges.h>

#include <iostream>
#include <ranges>
#include <vector>

int main() {
  std::vector<int> numbers = {1, 2, 3, 4, 5};

  // std::ranges::fold_left
  fmt::print("std::ranges::fold_left result: {}\n",
             std::ranges::fold_left(numbers, 0,
                                    [](int acc, int x) { return acc + x; }));

  // std::ranges::fold_left_first
  if (auto left_fold_first = std::ranges::fold_left_first(
          numbers, [](int acc, int x) { return acc + x; });
      left_fold_first) {
    fmt::print("std::ranges::fold_left_first result: {}\n", *left_fold_first);
  }

  // std::ranges::fold_right
  fmt::print("std::ranges::fold_right result: {}\n",
             std::ranges::fold_right(numbers, 0,
                                     [](int x, int acc) { return acc + x; }));

  // std::ranges::fold_right_last
  if (auto right_fold_last = std::ranges::fold_right_last(
          numbers, [](int x, int acc) { return acc + x; });
      right_fold_last) {
    fmt::print("std::ranges::fold_right_last result: {}\n", *right_fold_last);
  }

  // std::ranges::fold_left_with_iter
  fmt::print("std::ranges::fold_left_with_iter result: {}\n",
             std::ranges::fold_left_with_iter(
                 numbers, 0, [](auto iter, int acc, int x) {
                   fmt::print("Current element at index {}: {}\n",
                              std::distance(numbers.begin(), iter), x);
                   return acc + x;
                 }));

  // std::ranges::fold_left_first_with_iter
  if (auto left_fold_first_with_iter = std::ranges::fold_left_first_with_iter(
          numbers,
          [](auto iter, int acc, int x) {
            fmt::print("Current element at index {}: {}\n",
                       std::distance(numbers.begin(), iter), x);
            return acc + x;
          });
      left_fold_first_with_iter) {
    fmt::print("std::ranges::fold_left_first_with_iter result: {}\n",
               *left_fold_first_with_iter);
  }

  return 0;
}
