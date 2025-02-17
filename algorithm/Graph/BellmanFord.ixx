module;
#include <fmt/core.h>
#include <fmt/ranges.h>

#include <algorithm>
#include <tuple>
#include <vector>

export module Graph.BellmanFord;
import Graph.AdjList;
import Graph.Interface;

export namespace graph {
class BellmanFord {
 public:
  explicit BellmanFord(const AdjList& graph, Vertex src)
      : src_(src), graph_(graph) {}

  std::pair<unsigned, std::vector<unsigned>> computeShortestPath(unsigned dst) {
    bellmanFord(src_);
    if (parent_[dst] == -1) {
      return make_pair(0, std::vector<unsigned>());
    }

    unsigned distance = distances_[dst];

    std::vector<unsigned> path;
    path.push_back(dst);
    auto current = dst;
    while (current != src_) {
      current = parent_[current];
      path.push_back(current);
    }

    std::reverse(path.begin(), path.end());
    return make_pair(distance, path);
  }

 private:
  void bellmanFord(unsigned src) {
    distances_.resize(graph_.V(), -1);
    parent_.resize(graph_.V(), -1);
    distances_[src] = 0;
    parent_[src] = src;

    auto edges = graph_.GetWeightedEdges();

    for (unsigned i = 0; i < graph_.V() - 1; i++) {
      bool updated = false;
      for (auto [u, v, weight] : edges) {
        if (distances_[u] == -1) continue;
        if (distances_[v] == -1 || distances_[u] + weight < distances_[v]) {
          distances_[v] = distances_[u] + weight;
          parent_[v] = u;
          updated = true;
        }
      }
      if (!updated) break;
    }

    for (auto [u, v, weight] : edges) {
      if (distances_[u] == -1) continue;
      if (distances_[v] == -1 || distances_[u] + weight < distances_[v]) {
        throw std::runtime_error("Graph contains negative cycle");
      }
    }
  }

 private:
  Vertex src_;
  const AdjList& graph_;
  std::vector<int> distances_;
  std::vector<unsigned> parent_;
};
}  // namespace graph
