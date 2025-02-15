import Graph.AdjList;
import Graph.DFS;

int main() {
  graph::AdjList graph(5, false, false);
  graph.AddEdge(0, 1);
  graph.AddEdge(0, 4);
  graph.AddEdge(1, 2);
  graph.AddEdge(2, 3);
  graph.AddEdge(2, 4);
  graph.AddEdge(3, 4);

  graph::DFS dfs(graph);
  dfs.visit();

  return 0;
}
