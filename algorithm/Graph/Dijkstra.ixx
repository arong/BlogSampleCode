module;
#include <fmt/core.h>

#include <algorithm>
#include <queue>
#include <vector>

export module Graph.Dijkstra;
import Graph.Interface;
import Graph.AdjList;

export namespace graph {
class Dijkstra {
 public:
  explicit Dijkstra(const AdjList& graph, Vertex src)
      : src_(src),
        graph_(graph),
        distances_(graph.V(), INT_MAX),
        parent_(graph.V()) {
    dijkstra();
  }

  [[nodiscard]] int Distance(Vertex v) { return distances_[v]; }
  [[nodiscard]] std::vector<WeightedEdge> Path(Vertex v) {
    std::vector<WeightedEdge> path;

    auto curr = v;
    while (parent_[curr] != src_) {
      path.emplace_back(parent_[curr], curr,
                        graph_.GetWeight(parent_[curr], curr));
      curr = parent_[curr];
    }
    path.emplace_back(src_, curr, graph_.GetWeight(src_, curr));
    std::reverse(path.begin(), path.end());
    return path;
  }

  [[nodiscard]] std::string FormatAsDot() const {
    std::string dot;
    dot.append("digraph Dijkstra {\n");
    dot.append("\trankdir=LR;\n");
    dot.append("\tnode [shape=record];\n\n");
    for (Vertex u = 0; u < graph_.V(); u++) {
      fmt::format_to(std::back_inserter(dot),
                     "\t{}[label=\"{}|Distance={}\"];\n", u, u, distances_[u]);
    }
    dot.push_back('\n');
    for (Vertex u = 0; u < graph_.V(); u++) {
      for (auto v : graph_.Adj(u)) {
        std::string color("black");
        if (parent_[v] == u) color = "red";
        fmt::format_to(std::back_inserter(dot),
                       "\t{}->{}[label={},color={}];\n", u, v,
                       graph_.GetWeight(u, v), color);
      }
    }
    dot.append("}\n");
    return dot;
  }

 private:
  void dijkstra() {
    auto cmp = [](const auto& lhs, const auto& rhs) {
      return lhs.second > rhs.second;
    };

    std::priority_queue<std::pair<Vertex, int>,
                        std::vector<std::pair<Vertex, int>>, decltype(cmp)>
        q(cmp);
    q.push({src_, 0});
    distances_[src_] = 0;
    std::vector<bool> visited(graph_.V(), false);
    while (!q.empty()) {
      auto [u, distance] = q.top();
      q.pop();

      if (visited[u]) continue;
      visited[u] = true;
      // fmt::print("checking {} {}\n", u, distance);

      for (auto v : graph_.Adj(u)) {
        auto weight = graph_.GetWeight(u, v);
        if (distances_[v] == INT_MAX ||
            distances_[u] + weight < distances_[v]) {
          distances_[v] = distances_[u] + weight;
          parent_[v] = u;
          q.emplace(v, distances_[v]);
        }
      }
    }
  }

 private:
  Vertex src_;
  const AdjList& graph_;
  std::vector<int> distances_;
  std::vector<Vertex> parent_;
};
}  // namespace graph
