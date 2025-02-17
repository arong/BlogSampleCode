#include <fmt/core.h>

import Graph.BellmanFord;
import Graph.AdjList;

int main() {
  // negative edge
  graph::AdjList graph(9, false, true);
  graph.AddEdge(0, 1, 3);  // A - B (3)
  graph.AddEdge(0, 3, 4);  // A - D (4)

  graph.AddEdge(1, 2, 3);  // B - C (3)
  graph.AddEdge(1, 3, 5);  // B - D (5)
  graph.AddEdge(1, 4, 2);  // B - E (2)

  graph.AddEdge(2, 5, 2);  // C - F (2)

  graph.AddEdge(3, 6, 2);  // D - G (2)
  graph.AddEdge(3, 7, 3);  // D - H (3)

  graph.AddEdge(4, 5, 3);  // E - F (3)
  graph.AddEdge(4, 7, 2);  // E - H (2)
  graph.AddEdge(4, 8, 5);  // E - M (5)

  graph.AddEdge(5, 8, -4);  // F - M (-4)

  graph.AddEdge(6, 8, 6);  // G - M (6)

  graph.AddEdge(7, 8, 4);  // H - M (4)

  fmt::println("{}", graph.FormatAsDot());

  graph::BellmanFord bf(graph, 0);
  auto ret = bf.computeShortestPath(8);
  fmt::println("path length {}, details: {}", ret.first, ret.second);
}
