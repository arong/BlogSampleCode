module;

#include <fmt/core.h>

#include <fstream>
#include <map>
#include <sstream>
#include <stack>
#include <string>

export module Graph.DFS;
import Graph.AdjList;

export namespace graph {

class DFS {
 public:
  DFS(const AdjList& graph) : graph_(graph) {}

  void visit() {
    std::vector<bool> visited(graph_.V(), false);
    std::vector<int> parent(graph_.V(), -1);  // 初始化父节点数组

    for (unsigned i = 0; i < graph_.V(); ++i) {
      if (!visited[i]) {
        visitComponent(i, visited, parent);
      }
    }
  }

 private:
  void visitComponent(unsigned start, std::vector<bool>& visited,
                      std::vector<int>& parent) {
    std::stack<unsigned> s;

    s.push(start);
    visited[start] = true;

    while (!s.empty()) {
      unsigned curr = s.top();
      s.pop();

      // 处理当前节点，输出当前节点及其父节点
      if (parent[curr] != -1) {
        fmt::println("Visited node: {}, Parent node: {}", curr, parent[curr]);
      } else {
        fmt::println("Visited node: {} (no parent)", curr);
      }

      for (auto w : graph_.Adj(curr)) {
        if (!visited[w]) {
          visited[w] = true;
          parent[w] = curr;  // 记录父节点
          s.push(w);
        }
      }
    }
  }

 private:
  const AdjList& graph_;
};

}  // namespace graph
