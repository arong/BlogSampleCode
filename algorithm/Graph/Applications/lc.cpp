class UnionFind {
 public:
  explicit UnionFind(size_t size) : parent_(size), rank_(size, 1), cc_(size) {
    std::iota(parent_.begin(), parent_.end(), 0);
  }

  void Union(size_t u, size_t v) {
    int a = Find(u);
    int b = Find(v);
    if (a == b) return;

    if (rank_[a] < rank_[b]) {
      std::swap(a, b);
    }
    parent_[b] = a;
    rank_[a] += rank_[b];
    cc_--;
  }

  bool IsConnected(size_t u, size_t v) { return Find(u) == Find(v); }

  size_t CC() const { return cc_; }

 private:
  size_t Find(size_t x) {
    if (parent_[x] == x) return x;
    return parent_[x] = Find(parent_[x]);
  }

  ::std::vector<size_t> parent_;
  ::std::vector<size_t> rank_;
  size_t cc_;
};

class Solution {
 public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    // scan half
    UnionFind uf(isConnected.size());
    for (int i = 0; i < isConnected.size(); i++) {
      for (int j = i + 1; j < isConnected[0].size(); j++) {
        if (isConnected[i][j]) {
          uf.Union(i, j);
        }
      }
    }
    return uf.CC();
  }
};
