module;
#include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/ranges.h>

#include <queue>
#include <vector>

export module Graph.BFS;
import Graph.AdjList;
import Graph.Interface;

export namespace graph {

class BFS {
 public:
  BFS(const AdjList& graph) : graph_(graph) {}

  void visit() {
    std::vector<bool> visited(graph_.V(), false);
    std::vector<unsigned> parent(graph_.V(),
                                 UINT_MAX);  // UINT_MAX表示没有父节点

    for (unsigned i = 0; i < graph_.V(); ++i) {
      if (!visited[i]) {
        visitComponent(i, visited, parent);
      }
    }
  }

 private:
  void visitComponent(unsigned start, std::vector<bool>& visited,
                      std::vector<unsigned>& parent) {
    std::queue<unsigned> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
      unsigned curr = q.front();
      q.pop();

      // 处理当前节点并打印父节点
      if (parent[curr] != UINT_MAX) {
        fmt::println("Visited node: {} (from node: {})", curr, parent[curr]);
      } else {
        fmt::println("Visited node: {} (no parent)", curr);
      }

      for (auto w : graph_.Adj(curr)) {
        if (!visited[w]) {
          visited[w] = true;
          parent[w] = curr;  // 记录父节点
          q.push(w);
        }
      }
    }
  }

 private:
  const AdjList& graph_;
};

}  // namespace graph
