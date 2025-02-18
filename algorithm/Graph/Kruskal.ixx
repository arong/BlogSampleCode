module;

#include <algorithm>
#include <map>
#include <set>
#include <stdexcept>
#include <tuple>
#include <vector>

export module Graph.Kruskal;
import Graph.AdjList;
import Graph.Interface;
import Graph.UnionFind;

export namespace graph {
class Kruskal {
 public:
  explicit Kruskal(const AdjList& graph) : graph_(graph), uf_(graph.V()) {}

 public:
  std::pair<int, std::vector<WeightedEdge>> MST() {
    if (mst_.empty()) {
      kruskal();
    }
    int weight = 0;
    for (auto edge : mst_) {
      weight += std::get<2>(edge);
    }
    return make_pair(weight, mst_);
  }

 private:
  void kruskal() {
    auto edges = graph_.GetWeightEdges();
    std::sort(edges.begin(), edges.end(),
              [](const WeightedEdge& lhs, const WeightedEdge& rhs) {
                return std::get<2>(lhs) < std::get<2>(rhs);
              });
    for (auto& edge : edges) {
      auto& [begin, end, weight] = edge;
      if (!uf_.IsConnected(begin, end)) {
        mst_.emplace_back(edge);
        uf_.Union(begin, end);
      }
    }
  }

 private:
  const AdjList& graph_;
  graph::UnionFind uf_;
  std::vector<WeightedEdge> mst_;
};
}  // namespace graph
