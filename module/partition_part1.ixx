module;

#include <utility>
#include <vector>

export module partition:part1;

export namespace sort {
void bubble_sort(std::vector<int>& arr) {
  if (arr.size() < 2) return;
  for (int i = 0; i < arr.size() - 1; i++) {
    auto swapped = false;
    for (int j = 1; j < arr.size() - i; j++) {
      if (arr[j - 1] > arr[j]) {
        std::swap(arr[j - 1], arr[j]);
        swapped = true;
      }
    }
    if (!swapped) break;
  }
}
}  // namespace sort
