#include <fmt/ranges.h>

import Graph.AdjList;
import Graph.Kosaraju;
import Graph.Tarjan;

int main() {
  graph::AdjList graph(6, true, false);
  graph.AddEdge(0, 1);
  graph.AddEdge(1, 2);
  graph.AddEdge(2, 0);
  graph.AddEdge(2, 3);
  graph.AddEdge(3, 4);
  graph.AddEdge(4, 5);
  graph.AddEdge(5, 3);

  graph::Kosaraju scc(graph);
  auto ret = scc.GetSCC();
  for (auto &v : ret) {
    fmt::println("{}", v);
  }
  return 0;
}
