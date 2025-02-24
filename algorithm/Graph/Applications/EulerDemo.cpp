#include <fmt/ranges.h>

#include <vector>

import Graph.AdjList;
import Graph.Hierholzer;

int main() {
  graph::AdjList graph(9, false, false);
  graph.AddEdge(0, 1);
  graph.AddEdge(0, 3);
  graph.AddEdge(1, 2);
  graph.AddEdge(1, 4);
  graph.AddEdge(1, 5);
  graph.AddEdge(2, 5);
  graph.AddEdge(3, 4);
  graph.AddEdge(3, 6);
  graph.AddEdge(3, 7);
  graph.AddEdge(4, 5);
  graph.AddEdge(4, 7);
  graph.AddEdge(5, 8);
  graph.AddEdge(6, 7);
  graph.AddEdge(7, 8);

  graph::Hierholzer hierholzer(graph);
  fmt::println("Euler check: {}", hierholzer.IsEulerian());

  auto ret = hierholzer.FindEulerCircuit(0);
  std::vector<char> result;
  for (auto &i : ret) {
    result.push_back(i + 'A');
  }
  fmt::println("Euler path: {}", result);
  return 0;
}
