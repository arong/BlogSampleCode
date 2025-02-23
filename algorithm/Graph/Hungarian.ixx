module;

#include <fmt/core.h>

#include <algorithm>
#include <queue>
#include <stdexcept>
#include <string>
#include <vector>

export module Graph.Hungarian;
import Graph.Bipartite;
import Graph.Interface;
import Graph.CC;

export namespace graph {

class Hungarian {
 public:
  explicit Hungarian(const Graph& graph)
      : graph_(graph), visited_(graph_.V()), matching_(graph_.V(), -1) {
    graph::Bipartite bipartite(graph_);
    if (!bipartite.IsBipartite()) {
      throw std::runtime_error("Graph is not bipartite");
    }
    auto colors = bipartite.Colors();
    for (size_t i = 0; i < colors.size(); ++i) {
      if (colors[i] == graph::Color::Red) {
        left_.push_back(i);
      } else {
        right_.push_back(i);
      }
    }
  }

  std::pair<int, std::vector<int>> MaxMatching() {
    int result = 0;
    for (auto v : left_) {
      if (matching_[v] == -1) {
        std::fill(visited_.begin(), visited_.end(), false);
        if (FindAugmentingPath(v)) {
          result++;
        }
      }
    }
    return {result, matching_};
  }

 private:
  bool FindAugmentingPath(int v) {
    visited_[v] = true;
    for (int u : graph_.Adj(v)) {
      if (!visited_[u]) {
        visited_[u] = true;
        if (matching_[u] == -1 || FindAugmentingPath(matching_[u])) {
          matching_[u] = v;
          matching_[v] = u;
          return true;
        }
      }
    }
    return false;
  }

  const Graph& graph_;
  std::vector<bool> visited_;
  std::vector<int> matching_;
  std::vector<int> left_;
  std::vector<int> right_;
};
}  // namespace graph
