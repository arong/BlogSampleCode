module;

#include <algorithm>
#include <map>
#include <stdexcept>
#include <vector>

export module Graph.Kosaraju;
import Graph.AdjList;
import Graph.Interface;

export namespace graph {
class Kosaraju {
 public:
  explicit Kosaraju(const Graph& graph) : graph_(graph) {
    if (!graph.Directed()) throw std::runtime_error("graph is not directed");
  }

  std::vector<std::vector<Vertex>> GetSCC() {
    std::vector<std::vector<Vertex>> result;
    std::vector<Vertex> stack;  // 被当做栈来使用
    std::vector<bool> visited(graph_.V(), false);

    for (int i = 0; i < visited.size(); i++) {
      if (!visited[i]) {
        dfs(visited, i, stack, graph_);
      }
    }
    std::reverse(stack.begin(), stack.end());

    auto traverse = Transpose(graph_);
    visited.assign(graph_.V(), false);
    for (auto v : stack) {
      if (!visited[v]) {
        std::vector<unsigned> scc;
        dfs(visited, v, scc, traverse);
        result.push_back(scc);
      }
    }
    return result;
  }

 private:
  [[nodiscard]] AdjList Transpose(const Graph& graph) const {
    std::vector<std::pair<unsigned, unsigned>> edges;
    for (Vertex i = 0; i < graph.V(); i++) {
      for (auto u : graph.Adj(i)) {
        edges.emplace_back(u, i);
      }
    }
    return {graph.V(), edges, true};
  }
  void dfs(std::vector<bool>& visited, unsigned v, std::vector<unsigned>& path,
           const Graph& graph) {
    if (visited[v]) return;
    visited[v] = true;
    for (auto u : graph.Adj(v)) {
      if (!visited[u]) {
        dfs(visited, u, path, graph);
      }
    }
    path.push_back(v);
  }

 private:
  std::map<std::pair<Vertex, Vertex>, unsigned> steps_;
  const Graph& graph_;
};
}  // namespace graph
