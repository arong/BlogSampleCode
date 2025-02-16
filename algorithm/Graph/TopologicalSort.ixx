module;
#include <queue>
#include <stack>
#include <stdexcept>
#include <vector>

export module Graph.TopologicalSort;
import Graph.AdjList;
import Graph.Interface;

export namespace graph {
class TopologicalSortKahn {
 public:
  explicit TopologicalSortKahn(const AdjList& graph) : graph_(graph) {
    if (!graph_.Directed()) {
      throw std::invalid_argument(
          "Graph must be directed for topological sorting.");
    }
  }

  std::vector<Vertex> Sort() const {
    std::vector<Vertex> in_degree(graph_.V(), 0);
    std::queue<Vertex> q;
    std::vector<Vertex> topo_order;

    // Calculate in-degrees of all vertices
    for (Vertex u = 0; u < graph_.V(); ++u) {
      for (auto v : graph_.Adj(u)) {
        in_degree[v]++;
      }
    }

    // Enqueue all vertices with in-degree 0
    for (Vertex u = 0; u < graph_.V(); ++u) {
      if (in_degree[u] == 0) {
        q.push(u);
      }
    }

    // Process vertices in queue
    while (!q.empty()) {
      Vertex u = q.front();
      q.pop();
      topo_order.push_back(u);

      for (auto v : graph_.Adj(u)) {
        if (--in_degree[v] == 0) {
          q.push(v);
        }
      }
    }

    // Check if there was a cycle
    if (topo_order.size() != graph_.V()) {
      throw std::runtime_error(
          "Graph has at least one cycle, topological sort not possible.");
    }

    return topo_order;
  }

 private:
  const AdjList& graph_;
};

class TopologicalSortDFS {
 public:
  explicit TopologicalSortDFS(const AdjList& graph) : graph_(graph) {
    if (!graph_.Directed()) {
      throw std::invalid_argument(
          "Graph must be directed for topological sorting.");
    }
    visited_.resize(graph_.V(), false);
    on_stack_.resize(graph_.V(), false);
  }

  std::vector<Vertex> Sort() const {
    std::stack<Vertex> stack;
    std::vector<Vertex> topo_order;

    // Perform DFS for each vertex
    for (Vertex u = 0; u < graph_.V(); ++u) {
      if (!visited_[u]) {
        dfs(u, stack);
      }
    }

    // Pop from stack to get topological order
    while (!stack.empty()) {
      topo_order.push_back(stack.top());
      stack.pop();
    }

    return topo_order;
  }

 private:
  void dfs(Vertex u, std::stack<Vertex>& stack) const {
    visited_[u] = true;
    on_stack_[u] = true;

    for (auto v : graph_.Adj(u)) {
      if (!visited_[v]) {
        dfs(v, stack);
      } else if (on_stack_[v]) {
        throw std::runtime_error(
            "Graph has at least one cycle, topological sort not possible.");
      }
    }

    on_stack_[u] = false;
    stack.push(u);
  }

 private:
  const AdjList& graph_;
  mutable std::vector<bool> visited_;
  mutable std::vector<bool> on_stack_;
};
}  // namespace graph
