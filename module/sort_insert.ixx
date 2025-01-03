module;

#include <vector>

export module sort.insert;

export namespace sort {

void insertion_sort(std::vector<int>& arr) {
  for (int i = 1; i < arr.size(); i++) {
    auto k = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > k) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = k;
  }
}

}  // namespace sort
