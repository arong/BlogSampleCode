module;

#include <ctime>
#include <utility>
#include <vector>
#include <cstdlib>

export module sort.quick;

namespace sort {
int partition(std::vector<int>& arr, int l, int r) {
  std::swap(arr[l], arr[rand() % (r - l + 1) + l]);

  auto v = arr[l];
  int j = l;
  for (int i = l + 1; i <= r; i++)
    if (arr[i] < v) {
      j++;
      std::swap(arr[j], arr[i]);
    }

  std::swap(arr[l], arr[j]);

  return j;
}

void qs(std::vector<int>& arr, int l, int r) {
  if (r - l <= 0) return;

  int p = partition(arr, l, r);
  qs(arr, l, p - 1);
  qs(arr, p + 1, r);
}

export void quick_sort(std::vector<int>& arr) {
  srand(time(NULL));
  qs(arr, 0, arr.size() - 1);
}
}  // namespace sort
