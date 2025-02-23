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
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    UnionFind uf(edges.size());
    vector<int> result;
    for (auto& edge : edges) {
      int a = edge[0] - 1;
      int b = edge[1] - 1;
      if (uf.IsConnected(a, b)) {
        result.swap(edge);
      } else {
        uf.Union(a, b);
      }
    }
    return result;
  }
};
