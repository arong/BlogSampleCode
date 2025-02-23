#include <fmt/ranges.h>

import Graph.AdjList;
import Graph.Hungarian;

int main() {
  graph::AdjList graph(7, false, false);
  graph.AddEdge(0, 3);
  graph.AddEdge(0, 4);
  graph.AddEdge(1, 4);
  graph.AddEdge(1, 5);
  graph.AddEdge(2, 5);
  graph.AddEdge(2, 6);

  graph::Hungarian hungarian(graph);
  auto [cnt, matching] = hungarian.MaxMatching();
  fmt::println("{}", cnt);
  fmt::println("{}", matching);
  return 0;
}
