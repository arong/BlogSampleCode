#include <fmt/ranges.h>

import Graph.AdjList;
import Graph.TopologicalSort;

int main() {
  graph::AdjList graph(6, true, false);
  graph.AddEdge(0, 1);
  graph.AddEdge(0, 2);
  graph.AddEdge(1, 3);
  graph.AddEdge(2, 3);
  graph.AddEdge(3, 4);
  graph.AddEdge(5, 2);

  graph::TopologicalSortKahn topo(graph);
  auto ret = topo.Sort();
  fmt::println("{}", ret);

  graph::TopologicalSortDFS topo2(graph);
  ret = topo2.Sort();
  fmt::println("{}", ret);
  return 0;
}
