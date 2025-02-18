module;
#include <fmt/core.h>

#include <algorithm>
#include <queue>
#include <vector>

export module Graph.Prim;
import Graph.AdjList;
import Graph.Interface;

export namespace graph {
typedef std::pair<unsigned, int> EdgeWithWeight;
class Prim {
 public:
  explicit Prim(const AdjList& graph) : graph_(graph) { prim(); }
  std::pair<int, std::vector<WeightedEdge>> MST() { return {weight_, mst_}; }

 private:
  void prim() {
    std::vector<bool> visited(graph_.V(), false);
    std::vector<int> dist(graph_.V(), INT_MAX);
    std::vector<unsigned> parent(graph_.V(), UINT_MAX);
    auto compare = [](const auto& lhs, const auto& rhs) {
      return std::get<2>(lhs) > std::get<2>(rhs);
    };
    std::priority_queue<WeightedEdge, std::vector<WeightedEdge>,
                        decltype(compare)>
        pq(compare);
    dist[0] = 0;
    visited[0] = true;

    for (auto v : graph_.Adj(0)) {
      pq.push({0, v, graph_.GetWeight(0, v)});
    }

    while (!pq.empty()) {
      auto [u, v, weight] = pq.top();
      pq.pop();
      if (visited[v] && visited[u]) continue;
      mst_.push_back({u, v, weight});
      weight_ += weight;

      auto n = visited[v] ? u : v;
      visited[n] = true;
      fmt::print("visiting: {}->{} {} n={}\n", u, v, weight, n);

      for (auto& x : graph_.Adj(n)) {
        if (!visited[x]) {
          fmt::print("add {}->{}\n", n, x);
          pq.push({n, x, graph_.GetWeight(0, v)});
        }
      }
    }
  }

 private:
  int weight_ = 0;
  const AdjList& graph_;
  std::vector<WeightedEdge> mst_;
};
}  // namespace graph
