#include <fmt/core.h>
#include <fmt/ranges.h>

import Graph.AdjMatrix;

int main() {
  graph::AdjMatrix graph(5, false, false);
  graph.AddEdge(0, 1);
  graph.AddEdge(0, 4);
  graph.AddEdge(1, 2);
  graph.AddEdge(2, 3);
  graph.AddEdge(2, 4);
  graph.AddEdge(3, 4);

  fmt::println("number of vertices: {}", graph.V());
  fmt::println("number of edges: {}", graph.E());
  fmt::println("adjacency of {}: {}", 0, graph.Adj(0));
  fmt::println("{}", graph.FormatAsDot());
}
