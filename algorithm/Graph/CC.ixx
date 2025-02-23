module;
#include <queue>
#include <stdexcept>
#include <vector>

export module Graph.CC;
import Graph.Interface;
export namespace graph {
void VisitBFS(const Graph& graph, Vertex u, std::vector<bool>& visited) {
  if (visited[u]) return;
  std::queue<Vertex> q;
  q.push(u);
  while (!q.empty()) {
    auto c = q.front();
    q.pop();
    visited[c] = true;
    for (auto v : graph.Adj(c)) {
      if (visited[v]) continue;
      q.push(v);
    }
  }
}
int CC(const Graph& graph) {
  if (graph.Directed())
    throw std::runtime_error("CC only works for undirected graphs");
  std::vector<bool> visited(graph.V(), false);
  int cc = 0;
  for (auto i = 0; i < graph.V(); i++) {
    if (!visited[i]) {
      cc++;
      VisitBFS(graph, i, visited);
    }
  }
  return cc;
}
}  // namespace graph
